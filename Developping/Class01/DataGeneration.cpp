#include "DataGeneration.h"
#include <vector>
#include <map>
#include <string>


using namespace std;


DataGeneration :: DataGeneration(vector<int> vType, vector<double> rY, vector<int> rActions, vector<double> rCont, vector<int> rOrd, vector<int> rNom){
    sampleSize = 0;

    varType = vType;
    rangesY = rY;
    rangesActions = rActions;
    rangesCont = rCont;
    rangesOrd = rOrd;
    rangesNom = rNom;
    covariateSize = vType.size();
}


void DataGeneration :: creatSamples(int sSize){
    sampleSize = sSize;
    id = patientID(sSize);
    vector<vector<int>> seeds = assignSeed(createSeed(getCovariateSize(),100), varType);
    varCont = sampleGenerator(seeds[0],rangesCont);
    varOrd = sampleGenerator(seeds[1],rangesOrd);
    varNom = sampleGenerator(seeds[2],rangesNom);
    varY = sampleGenerator(createSeed(getYSize(),10),rangesY);
    actions = sampleGenerator(createSeed(getActionSize(),50),rangesActions);
}


void DataGeneration :: preprocessing(){
    varContInt = percentileVec(varCont);
    dataSet = combineData(varContInt, varOrd, varNom);
    sumTreatment0 = sumTreatment0Cal();
}

vector<vector<int>> DataGeneration :: combineData(vector<vector<int>> varCont, vector<vector<int>> varOrd, vector<vector<int>> varNom){
    vector<vector<int>> dataSet;
    for(int i=0; i<getContVarSize() ;++i) dataSet.push_back(varCont[i]);
    for(int i=0; i<getOrdVarSize() ;++i) dataSet.push_back(varOrd[i]);
    for(int i=0; i<getNomVarSize() ;++i) dataSet.push_back(varNom[i]);
    return dataSet;
}

int DataGeneration :: getSampleSize(){  return sampleSize;  }
int DataGeneration :: getCovariateSize(){   return covariateSize;   }
int DataGeneration :: getYSize(){ return getRangeSize(rangesY); }
int DataGeneration :: getActionSize(){  return getRangeSize(rangesActions); }
int DataGeneration :: getContVarSize(){   return getRangeSize(rangesCont);  }
int DataGeneration :: getOrdVarSize() { return getRangeSize(rangesOrd); }
int DataGeneration :: getNomVarSize() { return getRangeSize(rangesNom); }

vector<int> DataGeneration :: getVarType(){ return varType; }
vector<vector<double>> DataGeneration :: getY(){  return varY;    }
vector<vector<int>> DataGeneration :: getActions(){ return actions; }
vector<vector<double>> DataGeneration :: getVarCont(){  return varCont; }
vector<vector<int>> DataGeneration :: getVarCont(int i){  return varContInt; }
vector<vector<int>> DataGeneration :: getVarOrd(){  return varOrd;  }
vector<vector<int>> DataGeneration :: getVarNom(){    return varNom;  }
vector<vector<int>> DataGeneration :: getDataSet(){   return dataSet; }
vector<int> DataGeneration :: getID(){    return id;  }

void DataGeneration :: printContVar(){
    cout<<'\n'<<getContVarSize()<<" continuous variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varCont);
    }
void DataGeneration :: printContVar(int i){
        cout<<'\n'<<getContVarSize()<<" percentile continuous variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varContInt);
    }
void DataGeneration :: printOrdVar(){
        cout<<'\n'<<getOrdVarSize()<<" ordinal variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varOrd);
    }
void DataGeneration :: printNomVar(){
        cout<<'\n'<<getNomVarSize()<<" nominal variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varNom);
    }
void DataGeneration :: printY(){
        cout<<'\n'<<getYSize()<<" Y , "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varY);
    }
void DataGeneration :: printAction(){
        cout<<'\n'<<getActionSize()<<" actions , "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(actions);
    }
void DataGeneration :: printDataSet(){
        cout<<'\n'<<getCovariateSize()<<" covariates , "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(dataSet);
    }

void DataGeneration :: printInfo(int i){
        switch(i){
            case 0:
                printContVar();break;
            case 1:
                printOrdVar();break;
            case 2:
                printNomVar();break;
            case 3:
                printAction();break;
            case 4:
                printY();break;
            case 5:
                printContVar(5);break;
            case 6:
                printDataSet();break;
            default:
                cout<<"You typed something wrong!";
        }
    }

void DataGeneration :: genReport(){
        cout<<"Generate "<<getSampleSize()<<" samples\n"
            <<"Covariate size: "<<getCovariateSize()
            <<"\tY size: "<<getYSize()
            <<"\tAction size: "<<getActionSize()<<'\n'
            <<"Continuous: "<<getContVarSize()
            <<"\tOrdinal: "<<getOrdVarSize()
            <<"\tNormal: "<<getNomVarSize()<<endl;
    }


vector<int> DataGeneration :: patientID(int noSample){
    vector<int> vectOut;
    if(noSample>0){
        for(int i=0;i<noSample;++i){
            vectOut.push_back(i);
        }
    }else{
        cout<<"No. of sample much be >0"<<endl;
        return vectOut;
    }
    return vectOut;
}

template<class T>
int DataGeneration :: getRangeSize(vector<T> vectIn){
        int vectSize = vectIn.size();
        if(vectSize%2 == 0){
            for(unsigned int i=0 ; i < vectSize; ++i){
                T lowBound = vectIn[2*i];
                T upperBound = vectIn[2*i+1];
                if(lowBound < upperBound){
                    return vectSize/2;
                }else{
                    cout<<"Error: Please check if lower bounds are smaller than upper bounds. \n";
                }
            }
        }else{
                cout<<"Error: Please check for complete ranges input. \n";
            }
        }

vector<int> DataGeneration :: createSeed(int varsize, int start){
    vector<int> seed;
    for(unsigned int i=0 ; i<varsize; ++i){
        seed.push_back(start+5*i);
    }
    return seed;
}




vector<vector<int>> DataGeneration :: assignSeed(vector<int> seed, vector<int> varType){
    vector<vector<int>> vectOut;
    vector<int> seedCont;
    vector<int> SeedOrd;
    vector<int> seedNom;
    for(unsigned int i=0; i<getCovariateSize(); ++i){
        int type = varType[i];
        if(type == 0){
            seedCont.push_back(seed[i]);
        }else if(type == 1){
            SeedOrd.push_back(seed[i]);
        }else if(type == 2){
            seedNom.push_back(seed[i]);
        }else{
            cout<<"Error about variable type input."<<endl;
        }
    }
    vectOut.push_back(seedCont);
    vectOut.push_back(SeedOrd);
    vectOut.push_back(seedNom);
    return vectOut;
}


double DataGeneration :: dataGenerator(unsigned seed, double lowerBound, double upperBound){
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution (lowerBound,upperBound);
    return distribution(generator);
}

int DataGeneration :: dataGenerator(unsigned seed, int nMin, int nMax){
    srand(seed);
    return nMin + (rand() % static_cast<int>(nMax - nMin + 1));
}

vector<vector<double>> DataGeneration :: sampleGenerator(vector<int> seed, vector<double> ranges){
    vector<vector<double>> vectOut;
    int noVariable = getRangeSize(ranges);
    int noSample = getSampleSize();
    for(unsigned int i=0 ; i < noVariable; ++i){
        vector<double> vectTemp;
        double lowBound = ranges[2*i];
        double upperBound = ranges[2*i+1];
        for(unsigned int j=0; j<noSample;++j){
            vectTemp.push_back(dataGenerator(seed[i]+j,lowBound,upperBound));
        }
        vectOut.push_back(vectTemp);
    }
    return vectOut;
}


vector<vector<int>> DataGeneration :: sampleGenerator(vector<int> seed, vector<int> ranges){
    vector<vector<int>> vectOut;
    int noVariable = getRangeSize(ranges);
    int noSample = getSampleSize();
    for(unsigned int i=0 ; i < noVariable; ++i){
        vector<int> vectTemp;
        int lowBound = ranges[2*i];
        int upperBound = ranges[2*i+1];
        for(unsigned int j=0; j<noSample;++j){
            vectTemp.push_back(dataGenerator(seed[i]+j,lowBound,upperBound));
        }
        vectOut.push_back(vectTemp);
    }
    return vectOut;
}

vector<int> DataGeneration :: percentileVec(vector<double> &vectIn){
    vector<int> vectOut;
    map<double, int> mapTemp = percentileMap(vectIn);
    for(const auto &row : vectIn){
        vectOut.push_back(mapTemp[row]);
    }
    return vectOut;
}

vector<vector<int>> DataGeneration :: percentileVec(vector<vector<double>> &vectIn){
    vector<vector<int>> vectOut;
    for(auto x : vectIn){
        vectOut.push_back(percentileVec(x));
    }
    return vectOut;
}

map<double, int> DataGeneration :: percentileMap(vector<double> &vectorIn){
    map<double, int> mapOut;
    vector<double> vectorSort = vectorIn;
    sort(vectorSort.begin(),vectorSort.end());
    int len = vectorSort.size();
    for(unsigned int i=0; i<len ;++i)
        mapOut.insert(make_pair(vectorSort[i],assignPercentile(percentile(len,i+1))));
    return mapOut;
}

double DataGeneration :: percentile(double len,double index){
    if(index>=0){
        return 100*(index-0.5)/len;
    }else{
        cout<<"Out of scope"<<endl;
    }
}

int DataGeneration :: assignPercentile(double p){
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



double DataGeneration :: sumTreatment0Cal(){
    double sum =0.0;
    for(int i=0; i<sampleSize; ++i){
        if(actions[0][i] != 1){
          sum += varY[0][i];
        }
    }
    return sum;
}


double DataGeneration :: getSum(){
    return sumTreatment0;
}


template<class T>
void DataGeneration :: print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}

template<class T>
void DataGeneration :: print2DVector(vector<vector<T>> const &vectIn){
    try {
        for(unsigned int j=0;j<vectIn[0].size();++j){
            for(unsigned int i=0;i<vectIn.size();++i){
                cout<<vectIn[i][j]<<' ';
            }
            cout<<endl;
        }
    }catch (const std::out_of_range& oor) {
        cerr << "Out of Range error in print2DVector. Please check empty input: " << oor.what() << '\n';
    }
}
