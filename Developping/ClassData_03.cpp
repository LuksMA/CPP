#include <vector>
#include <string>
#include <random>
#include <math.h>
#include <algorithm>
#include <iostream>
#include "Support.cpp"
#include "Print.cpp"

using namespace std;



class DataGeneration{
    /// Settings for generate data
    int sampleSize =0;
    int covariateSize = 0;

    vector<int> varType; // 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesY;
    vector<int> rangesActions;
    vector<double> rangesCont;
    vector<int> rangesOrd;
    vector<int> rangesNom;

    /// Generated raw data
    vector <string> id;
    vector<vector<double>> varY;
    vector<vector<int>> actions;
    vector<vector<double>> varCont;
    vector<vector<int>> varOrd;
    vector<vector<int>> varNom;

    /// Processed data
    vector<vector<int>> varContInt;
    vector<vector<int>> dataSet;

public:
    DataGeneration(vector<int> vType, vector<double> rY, vector<int> rActions, vector<double> rCont, vector<int> rOrd, vector<int> rNom){
        varType = vType;
        rangesY = rY;
        rangesActions = rActions;
        rangesCont = rCont;
        rangesOrd = rOrd;
        rangesNom = rNom;
        covariateSize = vType.size();
    }

    void creatSamples(int sSize){
        sampleSize = sSize;
        vector <string> id = patientID(sSize);
        vector<vector<int>> seeds = assignSeed(creatSeed(getCovariateSize(),100), varType);
        varCont = sampleGenerator(seeds.at(0),rangesCont);
        varOrd = sampleGenerator(seeds.at(1),rangesOrd);
        varNom = sampleGenerator(seeds.at(2),rangesNom);
        varY = sampleGenerator(creatSeed(getYSize(),10),rangesY);
        actions = sampleGenerator(creatSeed(getActionSize(),50),rangesActions);
    }

    void preprocessing(){
        varContInt = percentileVec(varCont);
        dataSet = combineData(varContInt, varOrd, varNom);
    }

    vector<vector<int>> combineData(vector<vector<int>> varCont, vector<vector<int>> varOrd, vector<vector<int>> varNom){
        vector<vector<int>> dataSet;
        for(int i=0; i<getContVarSize() ;++i) dataSet.push_back(varCont.at(i));
        for(int i=0; i<getOrdVarSize() ;++i) dataSet.push_back(varOrd.at(i));
        for(int i=0; i<getNomVarSize() ;++i) dataSet.push_back(varNom.at(i));
        return dataSet;
    }

    int getSampleSize(){
        return sampleSize;
    }
    int getCovariateSize(){
        return covariateSize;
    }
    int getYSize(){
        return getRangeSize(rangesY);
    }
    int getActionSize(){
        return getRangeSize(rangesActions);
    }
    int getContVarSize(){
        return getRangeSize(rangesCont);
    }
    int getOrdVarSize() {
        return getRangeSize(rangesOrd);
    }
    int getNomVarSize() {
        return getRangeSize(rangesNom);
    }

    vector<int> getVarType(){
        return varType;
    }
    vector<vector<double>> getY(){
        return varY;
    }
    vector<vector<int>> getActions(){
        return actions;
    }
    vector<vector<double>> getVarCont(){
        return varCont;
    }
    vector<vector<int>> getVarOrd(){
        return varOrd;
    }
    vector<vector<int>> getVarNom(){
        return varNom;
    }
    vector<vector<int>> getVarContPer(){
        return varContInt;
    }
    vector<vector<int>> getDataSet(){
        return dataSet;
    }

    void printContVar(){
        cout<<'\n'<<getContVarSize()<<" continuous variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varCont);
    }
    void printContVar(int i){
        cout<<'\n'<<getContVarSize()<<" percentile continuous variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varContInt);
    }
    void printOrdVar(){
        cout<<'\n'<<getOrdVarSize()<<" ordinal variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varOrd);
    }
    void printNomVar(){
        cout<<'\n'<<getNomVarSize()<<" nominal variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varNom);
    }
    void printY(){
        cout<<'\n'<<getYSize()<<" Y , "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varY);
    }
    void printAction(){
        cout<<'\n'<<getActionSize()<<" actions , "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(actions);
    }
    void printDataSet(){
        cout<<'\n'<<getCovariateSize()<<" actions , "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(dataSet);
    }

    template<class T>
    void printInfo(T t){
        switch(t){
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

    void genReport(){
        cout<<"Generate "<<getSampleSize()<<" samples\n"
            <<"Covariate size: "<<getCovariateSize()
            <<"\tY size: "<<getYSize()
            <<"\tAction size: "<<getActionSize()<<'\n'
            <<"Continuous: "<<getContVarSize()
            <<"\tOrdinal: "<<getOrdVarSize()
            <<"\tNormal: "<<getNomVarSize()<<endl;
    }

private:
vector<string> patientID(int noSample){
    vector <string> vectOut;
    if(noSample>0){
        for(int i=0;i<noSample;++i){
            vectOut.push_back("Patient"+to_string(i));
        }
    }else{
        cout<<"No. of sample much be >0"<<endl;
        return vectOut;
    }
}

template<class T>
    int getRangeSize(vector<T> vectIn){
        int vectSize = vectIn.size();
        if(vectSize%2 == 0){
            for(unsigned int i=0 ; i < vectSize; ++i){
                T lowBound = vectIn.at(2*i);
                T upperBound = vectIn.at(2*i+1);
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

vector<int> creatSeed(int varsize, int start){
    vector<int> seed;
    for(unsigned int i=0 ; i<varsize; ++i){
        seed.push_back(start+5*i);
    }
    return seed;
}




vector<vector<int>> assignSeed(vector<int> seed, vector<int> varType){
    vector<vector<int>> vectOut;
    vector<int> seedCont;
    vector<int> SeedOrd;
    vector<int> seedNom;
    for(unsigned int i=0; i<getCovariateSize(); ++i){
        int type = varType.at(i);
        if(type == 0){
            seedCont.push_back(seed.at(i));
        }else if(type == 1){
            SeedOrd.push_back(seed.at(i));
        }else if(type == 2){
            seedNom.push_back(seed.at(i));
        }else{
            cout<<"Error about variable type input."<<endl;
        }
    }
    vectOut.push_back(seedCont);
    vectOut.push_back(SeedOrd);
    vectOut.push_back(seedNom);
    return vectOut;
}


double dataGenerator(unsigned seed, double lowerBound, double upperBound){
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution (lowerBound,upperBound);
    return distribution(generator);
}

int dataGenerator(unsigned seed, int nMin, int nMax){
    srand(seed);
    return nMin + (rand() % static_cast<int>(nMax - nMin + 1));
}

vector<vector<double>> sampleGenerator(vector<int> seed, vector<double> ranges){
    vector<vector<double>> vectOut;
    int noVariable = getRangeSize(ranges);
    int noSample = getSampleSize();
    for(unsigned int i=0 ; i < noVariable; ++i){
        vector<double> vectTemp;
        double lowBound = ranges.at(2*i);
        double upperBound = ranges.at(2*i+1);
        for(unsigned int j=0; j<noSample;++j){
            vectTemp.push_back(dataGenerator(seed.at(i)+j,lowBound,upperBound));
        }
        vectOut.push_back(vectTemp);
    }
    return vectOut;
}


vector<vector<int>> sampleGenerator(vector<int> seed, vector<int> ranges){
    vector<vector<int>> vectOut;
    int noVariable = getRangeSize(ranges);
    int noSample = getSampleSize();
    for(unsigned int i=0 ; i < noVariable; ++i){
        vector<int> vectTemp;
        int lowBound = ranges.at(2*i);
        int upperBound = ranges.at(2*i+1);
        for(unsigned int j=0; j<noSample;++j){
            vectTemp.push_back(dataGenerator(seed.at(i)+j,lowBound,upperBound));
        }
        vectOut.push_back(vectTemp);
    }
    return vectOut;
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

map<double, int> percentileMap(vector<double> &vectorIn){
    map<double, int> mapOut;
    vector<double> vectorSort = vectorIn;
    sort(vectorSort.begin(),vectorSort.end());
    int len = vectorSort.size();
    for(unsigned int i=0; i<len ;++i)
        mapOut.insert(make_pair(vectorSort.at(i),assignPercentile(percentile(len,i+1))));
    return mapOut;
}

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

};

int main(){
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,3,0,5,0,10};
    vector<int> rangesNom = {0,3,0,5,0,10};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(20);
    data.preprocessing();
    data.printInfo(0);
    data.printInfo(1);
    data.printInfo(2);
    data.printInfo(5);
    data.printInfo(6);
}
