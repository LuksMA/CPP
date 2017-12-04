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


/// Get Individual Patient Info
int PatientData :: getPatientX( Patient * p, int i){
    return p->getX(i);
}
vector<int> PatientData :: getPatientAction( Patient * p ){
    return p->getAction();
}

vector<double> PatientData :: getPatientY( Patient * p ){
    return p->getY();
}




/// Print Individual Patient
void PatientData :: printPatientID( Patient * p ) {
    cout<<p->getID();
}
void PatientData :: printPatientX( Patient * p ) {
    print1DVector(p->getX());
}
void PatientData :: printPatientAction( Patient * p ){
    print1DVector(p->getAction());
}

void PatientData :: printPatientY( Patient * p ){
    print1DVector(p->getY());
}


/// Print Patients
//void PatientData :: printPatientsX(vector<Patient *> const &patients){
//    for(auto p : patients){
//        cout<<"ID: ";
//        printPatientID(p);
//        cout<<" \tX: ";
//        printPatientX(p);
//        cout<<endl;
//    }
//    cout<<endl;
//}
//
//void PatientData :: printPatientsXA(vector<Patient *> const &patients){
//    for(auto p : patients){
//        cout<<"ID: ";
//        printPatientID(p);
//        cout<<" \tX: ";
//        printPatientX(p);
//        cout<<"\tAction: ";
//        printPatientAction(p);
//        cout<<endl;
//    }
//    cout<<endl;
//}
//
//
//void PatientData :: printPatients(vector<Patient *> const &patients){
//    for(auto p : patients){
//        cout<<"ID: ";
//        printPatientID(p);
//        cout<<" \tX: ";
//        printPatientX(p);
//        cout<<"\tAction: ";
//        printPatientAction(p);
//        cout<<"\tY: ";
//        printPatientY(p);
//        cout<<endl;
//    }
//    cout<<endl;
//}



template<class T>
void PatientData :: print1DVector(vector<T> vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}
