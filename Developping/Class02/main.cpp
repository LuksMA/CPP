#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
//#include "NominalFilter.cpp"
//#include "ActionFilter.cpp"
#include "AllFilter.cpp"

using namespace std;

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
    data.printInfo(6);

    /// Create patient objects
    vector<Patient> patientsAll = creatPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),data.getID());
    vector<Patient> patientsEmpty;
    patientsEmpty.empty();
    pair<vector<Patient> , vector<Patient>> patients = make_pair(patientsAll,patientsEmpty);
    printPatients(patients.first);

    /// Create variable information objects
    vector<VariableInfo> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
    varInfo.at(6).printVarInfo();

    /// Filtering
    Filter *iOrdinal0;   OrdinalFilter cOrdinal0({0,5,-1}); iOrdinal0 = &cOrdinal0; /// var0, <5
    Filter *iOrdinal1;   OrdinalFilter cOrdinal1({3,2,1}); iOrdinal1 = &cOrdinal1;  /// var3, >=2
//    Filter *iNominal0;   NominalFilter cNominal0(varInfo.at(6).getComb({6,1})); iNominal0 = &cNominal0;    /// var 6, combination 1, {0}

    Filter *iAllFilter0;  AllFilter cAllFilter0;  iAllFilter0 = &cAllFilter0;
    cAllFilter0.addFilter(cOrdinal0);    cAllFilter0.addFilter(cOrdinal1);
//    Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
//    cAllFilter1.addFilter(cOrdinal0);    cAllFilter1.addFilter(cOrdinal1);  cAllFilter1.addFilter(cNominal0);


    /// Filter Result print
    cout<<"\nTest 1:"<<endl;
    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
    printPatientsX(cOrdinal0.meetCriteria(patients).first);
    cout<<"Test 1 (unselected): "<<endl;
    printPatientsX(cOrdinal0.meetCriteria(patients).second);

    cout<<"Test 2:"<<endl;
    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
    cout<<"Variable(Ordinal) 3, cut by 2, result for >= 2:"<<endl;
    printPatientsX(cAllFilter0. meetCriteria(patients).first);
    cout<<"Test 2 (unselected): "<<endl;
    printPatientsX(cAllFilter0. meetCriteria(patients).second);
//
//    cout<<"Test 3:"<<endl;
//    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
//    cout<<"Variable(Ordinal) 3, cut by 2, result for >= 3:"<<endl;
//    cout<<"Variable(Nominal) 6, check by combination no 1, {0}:"<<endl;
//    printPatientsX(cAllFilter1.meetCriteria(patients));
//
//    cAllFilter1.addFilter(cComplement);
//    cout<<"Test 4:"<<endl;
//    printPatientsX(cAllFilter1.meetCriteria(patients));


    return 0;
}

