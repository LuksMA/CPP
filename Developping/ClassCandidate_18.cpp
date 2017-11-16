#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>


using namespace std;

/// Define enumerator for variable type
enum dataType {
    cont,    ord,    nomi
};
string getEnumType(dataType);  // Check data type

/// Convert to string
template <typename T> std::string to_string(T value);

/// Generate Data, int type for Nominal and Ordinal, double type for Continuous
double dataGenerator(unsigned seed, double lowerBound, double upperBound);  // Set range for continuous variable
int dataGenerator(unsigned seed, int lowerBound, int upperBound);   // Set range for nominal or ordinal variable
vector<vector<double>> sampleGenerator(vector<int> seed, int noSample, int noVariable, vector<double> &ranges); // Generate sample of continuous variable
vector<vector<int>> sampleGenerator(vector<int>, int noSample, int noVariable, vector<int> &ranges); // Generate sample of nominal or ordinal variable
vector<string> patientID(int noSample); // Generate patient ID

/// Print 1D/2D vector
template<class T> void print2DVector(vector<vector<T>> const &vectIn);
template<class T> void print1DVector(vector<T> const &vectIn);

/// Print Map
template<class T1,class T2>
void printMap(map<T1,T2> mapIn);

/// Print Percentile
template<class T1,class T2>
void printPercent(map<T1,T2> mapIn,vector<T1> &vectIn);

/// Calculate percentile of a vector
double percentile(double, double);
int assignPercentile(double);
map<double, int> percentileMap(vector<double> &vectorIn);
vector<int> percentileVec(vector<double> &vectIn);
vector<vector<int>> percentileVec(vector<vector<double>> &vectIn);

/// Distinct values of Ordinal and Nominal variables
vector<int> uniqueValues(vector<int> &vectorIn);

/// Generate all possible subset of Nominal variable (No empty set)
template<class T>   map<vector<int>,vector<T>> mapSubsets(vector<T> &set, int varNum);
template<class T>   void printNominalMap(map<vector<int>,vector<T>> &mapIn);
vector<map<vector<int>,vector<int>>> nominalDictionary(vector<vector<int>> dataSet, vector<int> varType);
vector<int> checknNominalDictionary(vector<map<vector<int>,vector<int>>> nomDict,vector<int> index);

/// All cut pairs or Ordinal variables
template<class T>   void printOrdinalMap(map<vector<int>,vector<T>> &mapIn);
int Flip(int i){ return (i==1) ? -1:1;}
map<vector<int>, vector<int>> mapSequence(vector<int> &vectIn, int varNum);



/************************* Define Class ****************************************/
/// Class for patients
class Patient{
    string patientID;
    vector<int> valueX;
    vector<double> valueY;
    vector<int> type;

public:
    Patient(string ID,vector<int> X, vector<double> Y, vector<int> t){
        patientID = ID;
        valueX = X;
        valueY = Y;
        type = t;
    }

    string getPatientID(){  return patientID;   }
    vector<int> getX(){ return valueX;  }
    vector<int> getX(int i){
        vector<int> rt;
        try{
            rt.push_back(valueX.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return: ";
        }
        return rt;
    }
    vector<double> getY(){  return valueY;  }
    vector<double> getY(int i){
        vector<double> rt;
        try{
            rt.push_back(valueY.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return: ";
        }
        return rt;
    }
    vector<int> getDataType(){  return type;    }
    vector<int> getDataType(int i){
        vector<int> rt;
        try{
            rt.push_back(type.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return: ";
        }
        return rt;
    }
    int getSizeX(){
        return valueX.size();
    }
    int getSizeY(){
        return valueY.size();
    }
    void summary(){
        cout<<"Patient ID: "<< patientID<<endl;
        cout<<getSizeX()<<" Covariate (X); ";print1DVector(valueX);
        cout<<"Covariate type: ";print1DVector(type);
        for(auto t : type){
                cout<<getEnumType(dataType(t))<<' ';
        }
        cout<<'\n';
        cout<<getSizeY()<<" Reward (Y): ";print1DVector(valueY);
    }
};

void printPatients(vector<Patient> patients);
void printPatientsX(vector<Patient> patients);
vector<Patient> creatPatients(vector<vector<int>> dataSet,vector<vector<double>> Y,vector<int> varType, vector<string> patientID);



/// Filter class for define criteria
class ICriteria{
public:
    virtual vector<Patient> meetCriteria(vector<Patient> patients)=0;
};

class CriteriaOrdinal : public ICriteria{
    vector<int> myIndex;
public:
    CriteriaOrdinal(vector<int> index){
        myIndex = index;
    }
    vector<Patient> meetCriteria(vector<Patient> patients){
        vector<Patient> vectOut;
        int varNo = myIndex.at(0);
        int cut = myIndex.at(1);
        int dir = myIndex.at(2);
        switch(dir){
            case 1:
                for(auto patient : patients){
                    if(patient.getX(varNo).at(0) >= cut)
                        vectOut.push_back(patient);
                };break;
            case -1:
                for(auto patient : patients){
                    if(patient.getX(varNo).at(0) < cut)
                        vectOut.push_back(patient);
                };break;
            default:
                cout<<"Wrong direction input.";
        }
        return vectOut;
    }
};

class CriteriaNominal : public ICriteria{
    vector<int> myIndex;
public:
    CriteriaNominal(vector<int> index){
        myIndex = index;
    }
    vector<Patient> meetCriteria(vector<Patient> patients){
        vector<Patient> vectOut;
        int varNo = myIndex.at(0);
        int combNo = myIndex.at(1);
        vector<int> subSet(myIndex.begin()+2,myIndex.end());
        for(auto patient : patients){
            if(find(subSet.begin(), subSet.end(), patient.getX(varNo).at(0)) != subSet.end()){
                vectOut.push_back(patient);
            }
        }
        return vectOut;
    }
};


class AllFilter : public ICriteria{
    vector<ICriteria *> criterias;
public:
//    AllFilter(){
//    }
    void addFilter(ICriteria &A){
        criterias.push_back(&A);
    }
    void clearAllFilter(){
        criterias.clear();
    }

    vector<Patient> meetCriteria(vector<Patient> patients){
        vector<Patient> before = patients;
        vector<Patient> after;
        for(auto cr: criterias){
            vector<Patient> after = cr -> meetCriteria(before);
            before = after;
        }
        return before;
    }
};


/************************* Main Function ****************************************/
int main(){
    /// Generate data
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<vector<double>> varCont = sampleGenerator({100,105,110},20,3,rangesCont);
    vector<int> rangesOrd = {0,3,0,5,0,10};
    vector<vector<int>> varOrd = sampleGenerator({200,205,210},20,3,rangesOrd);
    vector<int> rangesNom = {0,3,0,5,0,10};
    vector<vector<int>> varNom = sampleGenerator({300,305,310},20,3,rangesNom);
    vector <string> id = patientID(20);
    vector<double> rangesY = {0.0,100.0};
    vector<vector<double>> varY = sampleGenerator({10},20,1,rangesY);
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal

    /// Preprocessing
    vector<vector<int>> varContConv = percentileVec(varCont); // Preprocessing for continuous variables
    vector<vector<int>> dataSet; // Create updated dataset
    for(int i=0; i<3 ;++i) dataSet.push_back(varContConv.at(i));
    for(int i=0; i<3 ;++i) dataSet.push_back(varOrd.at(i));
    for(int i=0; i<3 ;++i) dataSet.push_back(varNom.at(i));
    cout<<"Converted dataset:\n";
    print2DVector(dataSet);

    vector<map<vector<int>,vector<int>>> nomDict =  nominalDictionary(dataSet, varType); // Create Dictionary for nominal variable combinations

    /// Build Patient objects
    vector<Patient> patients = creatPatients(dataSet,varY,varType,id);
    cout<<"\nPatients: \n";
    printPatients(patients);

    /// Filters
    ICriteria *iOrdinal0 = new CriteriaOrdinal({0,5,-1}); /// var0, <5
    ICriteria *iOrdinal1;   CriteriaOrdinal cOrdinal1({0,5,-1});  /// var0, <5
    iOrdinal0 = &cOrdinal1;
    ICriteria *iOrdinal2;   CriteriaOrdinal cOrdinal2({3,3,1});   /// var3, >=3
    iOrdinal1 = &cOrdinal2;
    ICriteria *iAllFilter;  AllFilter cAllFilter;
    iAllFilter = &cAllFilter;
    cAllFilter.addFilter(cOrdinal1);    cAllFilter.addFilter(cOrdinal2);
    ICriteria *iNominal1; CriteriaNominal cNominal1(checknNominalDictionary(nomDict,{6,2}));      /// var 6, combination 2, {1}
    iNominal1 = &cNominal1;

    /// Filter Result print
    cout<<"Test 1:"<<endl;
    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
    printPatientsX(iOrdinal0-> meetCriteria(patients)); // First variable, cut by 2, result for < 2

    cout<<"Test 2:"<<endl;
    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
    cout<<"Variable(Ordinal) 3, cut by 6, result for >= 3:"<<endl;
    printPatientsX(iAllFilter-> meetCriteria(patients));

    cAllFilter.addFilter(cNominal1);
    cout<<"Test 3:"<<endl;
    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
    cout<<"Variable(Ordinal) 3, cut by 6, result for >= 3:"<<endl;
    cout<<"Variable(Nominal) 6, check by combination no 2, {1}:"<<endl;
    printPatientsX(iAllFilter-> meetCriteria(patients));
}




/************************* Defined Functions ****************************************/
/// Part 1. Data generation
double dataGenerator(unsigned seed, double lowerBound, double upperBound){
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution (lowerBound,upperBound);
    return distribution(generator);
}
int dataGenerator(unsigned seed, int nMin, int nMax){
    srand(seed);
    return nMin + (rand() % static_cast<int>(nMax - nMin + 1));
}

vector<vector<double>> sampleGenerator(vector<int> seed, int noSample, int noVariable, vector<double> &ranges){
    vector<vector<double>> vectOut;
    if(noVariable == ranges.size()/2.0){
        for(unsigned int i=0 ; i < noVariable; ++i){
            vector<double> vectTemp;
            double lowBound = ranges.at(2*i);
            double upperBound = ranges.at(2*i+1);
            if(lowBound < upperBound){
                for(unsigned int j=0; j<noSample;++j){
                    vectTemp.push_back(dataGenerator(seed.at(i)+j,lowBound,upperBound));
                }
            }else{
                cout<<"Error: Please check if lower bounds are smaller than upper bounds. \n";
                return vectOut;
            }
            vectOut.push_back(vectTemp);
        }
    }else{
        cout<<"Error: Please check if number of variable matches the ranges input. \n";
    }
    return vectOut;
}

vector<vector<int>> sampleGenerator(vector<int> seed, int noSample, int noVariable, vector<int> &ranges){
    vector<vector<int>> vectOut;
    if(noVariable == ranges.size()/2.0){
        for(unsigned int i=0 ; i < noVariable; ++i){
            vector<int> vectTemp;
            int lowBound = ranges.at(2*i);
            int upperBound = ranges.at(2*i+1);
            if(lowBound < upperBound){
                for(unsigned int j=0; j<noSample;++j){
                    vectTemp.push_back(dataGenerator(seed.at(i)+j,lowBound,upperBound));
                }
            }else{
                cout<<"Error: Please check if lower bounds are smaller than upper bounds. \n";
                return vectOut;
            }
            vectOut.push_back(vectTemp);
        }
    }else{
        cout<<"Error: Please if number of variable matches the ranges input. \n";
    }
    return vectOut;
}

vector<string> patientID(int noSample){
    vector <string> vectOut;
    if(noSample>0){
        for(int i=0;i<noSample;++i){
            vectOut.push_back("Patient"+to_string(i));
        }
    }else{
        cout<<"No of sample much be >0"<<endl;
        return vectOut;
    }
}


/// Part 2. Print
template<class T>
void print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']'<<endl;
}

template<class T>
void print2DVector(vector<vector<T>> const &vectIn){
    try {
        for(unsigned int j=0;j<vectIn.at(0).size();++j){
            for(unsigned int i=0;i<vectIn.size();++i){
                cout<<vectIn[i][j]<<' ';
            }
            cout<<endl;
        }
    }catch (const std::out_of_range& oor) {
        cerr << "Out of Range error in print2DVector. Please check empty input: " << oor.what() << '\n';
    }
}

void printPatientsX(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()
            <<" \tValue of X: ";
        print1DVector(patient.getX());
    }
    cout<<endl;
}


void printPatients(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()
            <<" \tValue of X: ";
        print1DVector(patient.getX());
        cout<<"Value of Y: ";
        print1DVector(patient.getY());
    }
    cout<<endl;
}


template<class T1,class T2>
void printMap(map<T1,T2> mapIn){
    map <double, int> :: iterator it = mapIn.begin();
    while(it != mapIn.end()){
        cout<<it->first<<" :: "<<it->second<<endl;
        it++;
    }
}

template<class T1,class T2>
void printPercent(map<T1,T2> mapIn,vector<T1> &vectIn){
    for(const auto &row : vectIn){
        cout<<row<<" :: "<<mapIn[row]<<endl;
    }
}


template<class T>
void printNominalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
        cout<<"Nominal variable "<<First[0]<<" with combination "<<First[1]<<": ";
        vector<int> Second = x.second;
        print1DVector(Second);
    }
}

template<class T>
void printOrdinalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
        cout<<"Ordinal variable "<<First[0]<<", with cut "<<First[1]<<",  (1 for >=, -1 for <) "<<First[2]<<": ";
        vector<int> Second = x.second;
        print1DVector(Second);
    }
}


/// Part 3. Converter continuous variables to integers by percentile
double percentile(double len,double index){
    if(index>=0){
        return 100*(index-0.5)/len;
    }else{
        cout<<"Out of scope"<<endl;
    }
}

int assignPercentile(double p){
    if (p < 0){
        cout<<"Out of scope"<<endl;
        return -1;
    }else if (p < 10){
        return 0;
    }else if (p < 20){
        return 1;
    }else if (p < 30){
        return 2;
    }else if (p < 40){
        return 3;
    }else if (p < 50){
        return 4;
    }else if (p < 60){
        return 5;
    }else if (p < 70){
        return 6;
    }else if (p < 80){
        return 7;
    }else if (p < 90){
        return 8;
    }else{
        return 9;
    }
}

map<double, int> percentileMap(vector<double> &vectorIn){
    map<double, int> mapOut;
    vector<double> vectorSort = vectorIn;
    sort(vectorSort.begin(),vectorSort.end());
    int len = vectorSort.size();
    for(unsigned int i=0; i<len ;++i)
        mapOut.insert(make_pair(vectorSort.at(i),assignPercentile(percentile(len,i+1))));
    return mapOut;
}

vector<int> percentileVec(vector<double> &vectIn){
    vector<int> vectOut;
    map<double, int> mapTemp = percentileMap(vectIn);
    for(const auto &row : vectIn){
        vectOut.push_back(mapTemp[row]);
    }
    return vectOut;
}

vector<vector<int>> percentileVec(vector<vector<double>> &vectIn){
    vector<vector<int>> vectOut;
    for(auto x : vectIn){
        vectOut.push_back(percentileVec(x));
    }
    return vectOut;
}

/// Part 4. Assign combinations
vector<int> uniqueValues(vector<int> &vectorIn){
    if(!vectorIn.empty()){
        sort(vectorIn.begin(), vectorIn.end());
        vector<int>::iterator it;
        it = unique (vectorIn.begin(), vectorIn.end());
        vectorIn.resize(distance(vectorIn.begin(),it));
    }else{
        cout<<"Warning: Empty vector detected. Please initialize vector."<<endl;
    }
    return vectorIn;
}

template<class T>
map<vector<int>,vector<T>> mapSubsets(vector<T> &set, int varN){
    map <vector<int>,vector<T>> mapOfCategorical;

	int max = 1 << set.size();
	for(int i = 0; i < max; i++) {
        vector<int> First;

		vector<T> Second;
		int j = i;
		int index = 0;
		while (j > 0) {
			if((j & 1) > 0)
				Second.push_back(set[index]);
                j >>= 1;
                index++;
		}
		if(!Second.empty()){
		    First.push_back(varN);
            First.push_back(i);
            mapOfCategorical.insert(make_pair(First,Second));
		}
	}
	return mapOfCategorical;
}

map<vector<int>, vector<int>> mapSequence(vector<int> &vectIn, int varNum){
    map<vector<int>, vector<int>> mapSeq;

    int flag = 1;
    for(int i=0;i<vectIn.size();++i){
        flag = Flip(flag);
        int index = i+1;
        if(flag==-1){
            vector<int> tempSecond(vectIn.begin(),vectIn.begin()+index);
            if(!tempSecond.empty()){
                vector<int> tempFirst ={varNum,i+1,flag};
                mapSeq.insert(make_pair(tempFirst,tempSecond));
            }
            i--;
        }else{
            vector<int> tempSecond(vectIn.begin()+index,vectIn.end());
            if(!tempSecond.empty()){
                vector<int> tempFirst ={varNum,i+1,flag};
                mapSeq.insert(make_pair(tempFirst,tempSecond));
            }
        }
    }
    return mapSeq;
}

vector<map<vector<int>,vector<int>>> nominalDictionary(vector<vector<int>> dataSet, vector<int> varType){
    vector<map<vector<int>,vector<int>>> nominalDict;
    for(int i=0; i<varType.size() ;++i){
        map <vector<int>,vector<int>> mapDict;
        vector<int> First = {0};
        vector<int> Second = {0};
        if(varType.at(i)==2){
            vector<int> uni = uniqueValues(dataSet.at(i));
            mapDict = mapSubsets(uni,i);
        }else{
            mapDict.insert(make_pair(First,Second));
        }
        nominalDict.push_back(mapDict);
    }
    return nominalDict;
}

vector<int> checknNominalDictionary(vector<map<vector<int>,vector<int>>> nomDict,vector<int> index){
    map <vector<int>,vector<int>> X = nomDict.at(index.at(0));
    vector<int> add = X[index];
    index.insert(index.end(),add.begin(),add.end());
    return index;
}


/// Part 5. Create objects
vector<Patient> creatPatients(vector<vector<int>> dataSet,vector<vector<double>> Y,vector<int> varType, vector<string> patientID){
    vector<Patient> patients;
    for(unsigned int j=0;j<dataSet.at(0).size();++j){
        vector<int> valueX;
        vector<double> valueY;
        for(unsigned int i=0;i<dataSet.size();++i){
            valueX.push_back(dataSet[i][j]);
        }
        for(unsigned int p=0;p<Y.size();++p){
            valueY.push_back(Y[p][j]);
        }
        patients.push_back(Patient(patientID.at(j),valueX,valueY,varType));
    }
    return patients;
}


/// Part 6 Support functions
string getEnumType(dataType d){
    switch(d){
        case cont:
            return "Continuous";
        case ord:
            return "Ordinal";
        case nomi:
            return "Nominal";
        default:
            return "You typed something wrong!";
    }
}


template <typename T>
std::string to_string(T value){
      //create an output string stream
      std::ostringstream os ;

      //throw the value into the string stream
      os << value ;

      //convert the string stream into a string and return
      return os.str() ;
}
