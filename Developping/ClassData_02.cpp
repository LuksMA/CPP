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

    vector <string> id;
    vector<vector<double>> varY;
    vector<vector<int>> actions;
    vector<vector<double>> varCont;
    vector<vector<int>> varOrd;
    vector<vector<int>> varNom;

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



    void printContVar(){
        cout<<'\n'<<getContVarSize()<<" continuous variables, "<<getSampleSize()<<" samples:"<<endl;
        print2DVector(varCont);
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
        seed.push_back(start+100*i);
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
    data.printInfo(4);


}
