#include "PatientData.h"


PatientData :: PatientData(){}

PatientData :: PatientData(DataGeneration & data)
{
    patientsData = createPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),data.getID());
}
PatientData :: PatientData(vector<Patient *> &dataSet){
    patientsData = dataSet;
}

PatientData :: ~PatientData(){  }

void PatientData :: printPatientsX(){
    for(auto p:patientsData){
        p->printPatientsX();
    }
}

void PatientData :: printPatientsXA(){
    for(auto p:patientsData){
        p->printPatientsXA();
    }
}


void PatientData :: printPatients(){
    for(auto p:patientsData){
        p->printPatients();
    }
}

vector<Patient *> PatientData :: createPatients(vector<vector<short>> dataSet,vector<vector<short>> actions, vector<vector<float>> Y,vector<short> varType, vector<short> patientID){
    vector<Patient *> patients;
    for(unsigned int j=0;j<dataSet.at(0).size();++j){
        vector<short> valueX;
        vector<float> valueY;
        vector<short> action;
        for(unsigned int i=0;i<dataSet.size();++i){
            valueX.push_back(dataSet[i][j]);
        }
        for(unsigned int p=0;p<Y.size();++p){
            valueY.push_back(Y[p][j]);
        }
        for(unsigned int q=0;q<actions.size();++q){
            action.push_back(actions[q][j]);
        }
        patients.push_back(new Patient(patientID[j], action , valueX ,valueY , varType));
    }
    return patients;
}




vector<Patient *> PatientData :: getPatients(){
    return patientsData;
}


