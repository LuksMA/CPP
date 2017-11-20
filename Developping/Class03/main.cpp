#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
#include "NominalFilter.cpp"
#include "ActionFilter.cpp"
#include "AllFilter.cpp"

using namespace std;


pair<pair<vector<int>,vector<int>>, double> OneDepthOrdinal(VariableInfo variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    vector<int> bIndex;
    vector<int> bRange;
    double bValue = 0;

    Filter *iAction1;  ActionFilter cAction1({1});    iAction1=&cAction1;

    for(auto x : variInfo.getCombs()){
        vector<int> First = x.first;
        vector<int> Second = x.second;

        Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
        Filter *iOrdinal1;   OrdinalFilter cOrdinal1(First); iOrdinal1 = &cOrdinal1;
        cAllFilter1.addFilter(cOrdinal1);
        cAllFilter1.addFilter(cAction1);

        double temp = expect(cAllFilter1.meetCriteria(patients).first,sampleSize)+expect(cAllFilter1.meetCriteria(patients).second,sampleSize);

        if(temp > bValue){
            bValue = temp;
            bRange = Second;
            bIndex = First;
        }
    }
    pairOut = make_pair(make_pair(bIndex, bRange),bValue);

    return pairOut;

}

pair<pair<vector<int>,vector<int>>, double> OneDepthNominal(VariableInfo variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    vector<int> bIndex;
    vector<int> bRange;
    double bValue = 0;

    Filter *iAction1;  ActionFilter cAction1({1});    iAction1=&cAction1;

    for(auto x : variInfo.getCombs()){
        vector<int> First = x.first;
        vector<int> Second = x.second;

        Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
        Filter *iNominal1;   NominalFilter  cNominal1(variInfo.getComb(First)); iNominal1 = &cNominal1;
        cAllFilter1.addFilter(cNominal1);
        cAllFilter1.addFilter(cAction1);

        double temp = expect(cAllFilter1.meetCriteria(patients).first,sampleSize)+expect(cAllFilter1.meetCriteria(patients).second,sampleSize);

        if(temp > bValue){
            bValue = temp;
            bRange = Second;
            bIndex = First;
        }
    }
    pairOut = make_pair(make_pair(bIndex, bRange), bValue);

    return pairOut;
}

pair<pair<vector<int>,vector<int>>, double> OneDepth(vector<VariableInfo> varInfo, pair<vector<Patient>,vector<Patient>> patients, DataGeneration data){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    double bValue = 0;
    int sampleSize = data.getSampleSize();
    vector<int> variType = data.getVarType();
    for(int i=0; i<data.getCovariateSize(); ++i){
        if(variType.at(i)==2){
            pair<pair<vector<int>,vector<int>>, double> tempPair = OneDepthNominal(varInfo.at(i),patients,sampleSize);
            if(tempPair.second>bValue){
                bValue = tempPair.second;
                pairOut = tempPair;
            }
        }else{
            pair<pair<vector<int>,vector<int>>, double> tempPair = OneDepthOrdinal(varInfo.at(i),patients,sampleSize);
            if(tempPair.second > bValue){
                bValue = tempPair.second;
                pairOut = tempPair;
            }
        }
    }
    return pairOut;
}




int main(){
    /// Test data generation class
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,3,0,5,0,10};
    vector<int> rangesNom = {0,3,0,5,0,10};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(20);
    data.preprocessing();
//    data.printInfo(6);

    /// Create patient objects
    vector<Patient> patientsAll = creatPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),data.getID());
    vector<Patient> patientsEmpty;
    patientsEmpty.empty();
    pair<vector<Patient> , vector<Patient>> patients = make_pair(patientsAll,patientsEmpty);
//    printPatients(patients.first);

    /// Create variable information objects
    vector<VariableInfo> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
//    varInfo.at(0).printVarInfo();


    /// Filtering 1 Depth
    /// Filter Result print
    pair<pair<vector<int>,vector<int>>, double> Result0 = OneDepthOrdinal(varInfo.at(0), patients, data.getSampleSize());
    cout<<Result0.second<<'\t';printPair(Result0.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result1 = OneDepthOrdinal(varInfo.at(1), patients, data.getSampleSize());
    cout<<Result1.second<<'\t';printPair(Result1.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result2 = OneDepthOrdinal(varInfo.at(2), patients, data.getSampleSize());
    cout<<Result2.second<<'\t';printPair(Result2.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result3 = OneDepthOrdinal(varInfo.at(3), patients, data.getSampleSize());
    cout<<Result3.second<<'\t';printPair(Result3.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result4 = OneDepthOrdinal(varInfo.at(4), patients, data.getSampleSize());
    cout<<Result4.second<<'\t';printPair(Result4.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result5 = OneDepthOrdinal(varInfo.at(5), patients, data.getSampleSize());
    cout<<Result5.second<<'\t';printPair(Result5.first);cout<<'\n';

    pair<pair<vector<int>,vector<int>>, double> Result6 = OneDepthNominal(varInfo.at(6), patients, data.getSampleSize());
    cout<<Result6.second<<'\t';printPair(Result6.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result7 = OneDepthNominal(varInfo.at(7), patients, data.getSampleSize());
    cout<<Result7.second<<'\t';printPair(Result7.first);cout<<'\n';
    pair<pair<vector<int>,vector<int>>, double> Result8 = OneDepthNominal(varInfo.at(8), patients, data.getSampleSize());
    cout<<Result8.second<<'\t';printPair(Result8.first);cout<<'\n';

    cout<<"All:"<<endl;
    pair<pair<vector<int>,vector<int>>, double> ResultAll = OneDepth(varInfo, patients, data);
    cout<<ResultAll.second<<'\t';printPair(ResultAll.first);cout<<'\n';




return 0;
}




