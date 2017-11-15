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

/// All cut pairs or Ordinal variables
template<class T>   void printOrdinalMap(map<vector<int>,vector<T>> &mapIn);
int Flip(int i){ return (i==1) ? -1:1;}
map<vector<int>, vector<int>> mapSequence(vector<int> &vectIn, int varNum);



/************************* Define Class ****************************************/
/// Class for patients
class Patient{
    string patientID;
    vector<int> action;
    vector<int> valueX;
    vector<double> valueY;
    vector<int> type;

public:
    Patient(string ID, vector<int> a, vector<int> X, vector<double> Y, vector<int> t){
        patientID = ID;
        action = a;
        valueX = X;
        valueY = Y;
        type = t;
    }
    string getPatientID(){  return patientID;   }
    vector<int> getAction(){  return action;  }
    vector<int> getAction(int i){
        vector<int> rt;
        try{
            rt.push_back(action.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getAction(). ";
        }
        return rt;
    }
    vector<int> getX(){ return valueX;  }
    vector<int> getX(int i){
        vector<int> rt;
        try{
            rt.push_back(valueX.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getX(). ";
        }
        return rt;
    }
    vector<double> getY(){  return valueY;  }
    vector<double> getY(int i){
        vector<double> rt;
        try{
            rt.push_back(valueY.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getY(). ";
        }
        return rt;
    }
    vector<int> getDataType(){  return type;    }
    vector<int> getDataType(int i){
        vector<int> rt;
        try{
            rt.push_back(type.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getDataType(). ";
        }
        return rt;
    }
    int getSizeAction(){    return action.size();   }
    int getSizeX(){ return valueX.size();   }
    int getSizeY(){ return valueY.size();   }
    void summary(){
        cout<<"Patient ID: "<< patientID<<endl;
        cout<<getSizeAction()<<" Action (A): ";print1DVector(action);
        cout<<getSizeY()<<" Reward (Y): ";print1DVector(valueY);
        cout<<getSizeX()<<" Covariate (X); ";print1DVector(valueX);
        cout<<"Covariate type: ";print1DVector(type);
//        for(auto t : type){
//                cout<<getEnumType(dataType(t))<<' ';
//        }
//        cout<<'\n';
    }
};

void printPatients(vector<Patient> patients);
void printPatientsX(vector<Patient> patients);
void printPatientsXA(vector<Patient> patients);
vector<Patient> creatPatients(vector<vector<int>> dataSet, vector<vector<int>> action, vector<vector<double>> Y , vector<int> varType , vector<string> patientID);


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

class CriteriaAction : public ICriteria{
    vector<int> myAction;
public:
    CriteriaAction(vector<int> action){
        myAction = action;
    }

    vector<Patient> meetCriteria(vector<Patient> patients){
        vector<Patient> vectOut;
        for(auto patient : patients){
            if(patient.getAction() == myAction){
                vectOut.push_back(patient);
            }
        }
        return vectOut;
    }
};

class CriteriaComplement : public ICriteria{
    vector<string> patientID;
public:
    CriteriaComplement(vector<string> id){
        patientID = id;
    }
    vector<Patient> meetCriteria(vector<Patient> patients){
        vector<Patient> vectOut;
        for(auto patient : patients){
            if(std::find(patientID.begin(), patientID.end(), patient.getPatientID()) != patientID.end()){
                vectOut.push_back(patient);
            }
        }
        return vectOut;
    }
};



class AllFilter : public ICriteria{
    vector<ICriteria *> criterias;
public:
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


/// Class for variables
class VariableInfo{
    int varNo;
    int varType;
    map<vector<int>, vector<int>> searchSets;
public:
    VariableInfo(int no, int type, vector<int> dataSetColumn){
        varNo = no;
        varType = type;
        map<vector<int>, vector<int>> mapDict;
        if(type==2){
            vector<int> uni = uniqueValues(dataSetColumn);
            mapDict = mapSubsets(uni,no);
        }else if(type==1){
            vector<int> uni = uniqueValues(dataSetColumn);
            mapDict = mapSequence(uni,no);
        }else if(type==0){
            vector<int> uni = uniqueValues(dataSetColumn);
            mapDict = mapSequence(uni,no);
        }else{
            cout<<"\nIn correct input for data type.\n";
        }
        searchSets = mapDict;
    }

    int getCombSize(){    return searchSets.size();   }
    int getVarNo(){ return varNo;   }
    int getVarType(){ return varType;   }
    map<vector<int>, vector<int>> getCombs(){ return searchSets; }

    vector<int> getComb(vector<int> vectIn) {
        if(getVarType()==2){
            vector<int> add = searchSets[vectIn];
            vectIn.insert(vectIn.end(),add.begin(),add.end());
            return vectIn;
        }else{
            return searchSets[vectIn];
        }
    }

    void getCombPrint(vector<int> vectIn){
        print1DVector(getComb(vectIn));
    }

    void printVarInfo(){
        cout<<"Variable number: "<<getVarNo()<<"\tType: "<<getEnumType(dataType(getVarType()))<<endl;
        cout<<getCombSize()<<" available combinations:"<<endl;
        if(getVarType()==2){
            printNominalMap(searchSets);
        }else{
            printOrdinalMap(searchSets);
        }
    }
};


vector<VariableInfo> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType);

double expect(vector<Patient> patients, int size){
    double out = 0;
    for(auto& patient : patients){
        out = out + patient.getY(0).at(0);
    }
    return out*2/10;
}



/************************* Main Function ****************************************/
int main(){
    /// Generate data
    vector<int> varType = {1};
    vector <string> id = {"1","2","3","4","5","6","7","8","9","10"};
    vector<vector<double>> varY = {{1,2,3,4,5,3,3,3,3,3}};
    vector<vector<int>> dataSet = {{1,2,3,4,5,1,2,3,4,5}};
    vector<vector<int>> actions ={{1,1,1,1,1,2,2,2,2,2}};

    /// Build variable information objects
    vector<Patient> patients = creatPatients(dataSet,actions,varY,varType,id);
    cout<<"\nPatients: \n";
    printPatients(patients);

    /// Filters
    ICriteria *iAdamT1; CriteriaOrdinal cAdamT1({0,2,1}); iAdamT1 = &cAdamT1;
    ICriteria *iAdamT2; CriteriaOrdinal cAdamT2({0,2,-1}); iAdamT2 = &cAdamT2;
    ICriteria *iBarryT1; CriteriaOrdinal cBarryT1({0,3,1}); iBarryT1 = &cBarryT1;
    ICriteria *iBarryT2; CriteriaOrdinal cBarryT2({0,3,-1}); iBarryT2 = &cBarryT2;
    ICriteria *iActionT1;  CriteriaAction cActionT1({1});    iActionT1=&cActionT1;
    ICriteria *iActionT2;  CriteriaAction cActionT2({2});    iActionT2=&cActionT2;

    ICriteria *iAllAdamT1;  AllFilter cAllAdamT1;  iAllAdamT1 = &cAllAdamT1;
    cAllAdamT1.addFilter(cAdamT1);
    cAllAdamT1.addFilter(cActionT1);

    ICriteria *iAllAdamT2;  AllFilter cAllAdamT2;  iAllAdamT2 = &cAllAdamT2;
    cAllAdamT2.addFilter(cAdamT2);
    cAllAdamT2.addFilter(cActionT2);

    ICriteria *iAllBarryT1;  AllFilter cAllBarryT1;  iAllBarryT1 = &cAllBarryT1;
    cAllBarryT1.addFilter(cBarryT1);
    cAllBarryT1.addFilter(cActionT1);
    ICriteria *iAllBarryT2;  AllFilter cAllBarryT2;  iAllBarryT2 = &cAllBarryT2;
    cAllBarryT2.addFilter(cBarryT2);
    cAllBarryT2.addFilter(cActionT2);

    /// Filter Result print
    cout<<"Doctor Adam (treatment 1):\n";
    printPatientsXA(iAdamT1-> meetCriteria(patients));
    cout<<"Doctor Adam (treatment 2):\n";
    printPatientsXA(iAdamT2-> meetCriteria(patients));
    cout<<"Doctor Barry (treatment 1):\n";
    printPatientsXA(iBarryT1-> meetCriteria(patients));
    cout<<"Doctor Barry (treatment 2):\n";
    printPatientsXA(iBarryT2-> meetCriteria(patients));


    cout<<"Doctor Adam (treatment 1, action 1):\n";
    printPatientsXA(iAllAdamT1-> meetCriteria(patients));
    cout<<"Doctor Adam (treatment 2, action 2):\n";
    printPatientsXA(iAllAdamT2-> meetCriteria(patients));
    cout<<"Doctor Barry (treatment 1, action 1):\n";
    printPatientsXA(iAllBarryT1-> meetCriteria(patients));
    cout<<"Doctor Barry (treatment 2, action 2):\n";
    printPatientsXA(iAllBarryT2-> meetCriteria(patients));

    cout<<"Doctor Adam: "<<expect(iAllAdamT1-> meetCriteria(patients),10)+expect(iAllAdamT2-> meetCriteria(patients),10)<<endl;
    cout<<"Doctor Barry: "<<expect(iAllBarryT1-> meetCriteria(patients),10)+expect(iAllBarryT2-> meetCriteria(patients),10)<<endl;
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
    cout<<']';
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
        cout<<endl;
    }
    cout<<endl;
}

void printPatientsXA(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()
            <<"\tValue of X: ";
        print1DVector(patient.getX());
        cout<<"\tAction: ";
        print1DVector(patient.getAction());
        cout<<endl;
    }
    cout<<endl;
}

void printPatients(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()<<endl;
        cout<<"Value of Y: ";
        print1DVector(patient.getY());
        cout<<"\tAction: ";
        print1DVector(patient.getAction());
        cout<<"\tValue of X: ";
        print1DVector(patient.getX());
        cout<<endl;
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
        cout<<'<'<<First[0]<<' '<<First[1]<<"> :: ";
        vector<int> Second = x.second;
        print1DVector(Second);
    }
}

template<class T>
void printOrdinalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
//        cout<<"Ordinal variable "<<First[0]<<", with cut "<<First[1]<<",  (1 for >=, -1 for <) "<<First[2]<<": ";
        cout<<'<'<<First[0]<<' '<<First[1]<<' '<<First[2]<<"> :: ";
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


/// Part 5. Create objects
vector<Patient> creatPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<string> patientID){
    vector<Patient> patients;
    for(unsigned int j=0;j<dataSet.at(0).size();++j){
        vector<int> valueX;
        vector<double> valueY;
        vector<int> action;
        for(unsigned int i=0;i<dataSet.size();++i){
            valueX.push_back(dataSet[i][j]);
        }
        for(unsigned int p=0;p<Y.size();++p){
            valueY.push_back(Y[p][j]);
        }
        for(unsigned int q=0;q<actions.size();++q){
            action.push_back(actions[q][j]);
        }
        patients.push_back(Patient(patientID.at(j), action , valueX ,valueY , varType));
    }
    return patients;
}

vector<VariableInfo> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType){
    vector<VariableInfo> variables;
    for(int i=0;i<varType.size();++i){
        variables.push_back(VariableInfo(i,varType.at(i),dataSet.at(i)));
    }
    return variables;
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
