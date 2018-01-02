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


vector<Patient *> PatientData :: createPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<int> patientID){
    vector<Patient *> patients;
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
        patients.push_back(new Patient(patientID.at(j), action , valueX ,valueY , varType));
    }
    return patients;
}




vector<Patient *> PatientData :: getPatients(){
    return patientsData;
}


/// Print Patients
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





