#include <iostream>
#include "Patient.h"
#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"


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
//    data.printInfo(6);

    vector<Patient> patients = creatPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),data.getID());
//    printPatients(patients);




    return 0;
}

