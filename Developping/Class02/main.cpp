#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
#include "NominalFilter.cpp"
#include "ActionFilter.cpp"
#include "AllFilter.cpp"

using namespace std;



pair<pair<vector<int>,vector<int>>, double> OneDepthOrdinal(map<vector<int>,vector<int>> variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    vector<int> bindex;
    vector<int> brange;
    double bvalue = 0;

    Filter *iAction1;  ActionFilter cAction1({1});    iAction1=&cAction1;

    for(auto x : variInfo){
        vector<int> First = x.first;
        vector<int> Second = x.second;

        Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
        Filter *iOrdinal1;   OrdinalFilter cOrdinal1(First); iOrdinal1 = &cOrdinal1;
        cAllFilter1.addFilter(cOrdinal1);
        cAllFilter1.addFilter(cAction1);

        double temp = expect(cAllFilter1.meetCriteria(patients).first,sampleSize)+expect(cAllFilter1.meetCriteria(patients).second,sampleSize);

        if(temp > bvalue){
            bvalue = temp;
            brange = Second;
            bindex = First;
        }
    }
    pairOut = make_pair(make_pair(bindex, brange),bvalue);

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
    cout<<data.getCovariateSize()<<endl;

    /// Filter Result print
    map<vector<int>,vector<int>> info0 = varInfo.at(0).getCombs();
    printOrdinalMap(info0);
    cout<<'\n';



    pair<pair<vector<int>,vector<int>>, double> Result = OneDepthOrdinal(info0, patients,data.getSampleSize());
    cout<<Result.second<<'\t';printPair(Result.first);



return 0;
}




