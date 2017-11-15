#include <vector>
#include <map>
#include <string>
#include "Patient.h"
#include "Print.cpp"

using namespace std;

Patient :: Patient(string ID, vector<int> a, vector<int> X, vector<double> Y, vector<int> t)
{
    patientID = ID;
    action = a;
    valueX = X;
    valueY = Y;
    type = t;
}

string Patient :: getPatientID(){  return patientID;   }
vector<int> Patient :: getAction(){  return action;  }
vector<int> Patient :: getAction(int i)
{
        vector<int> rt;
        try{
            rt.push_back(action.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getAction(). ";
        }
        return rt;
 }
vector<int> Patient :: getX(){ return valueX;  }
vector<int> Patient :: getX(int i)
{
        vector<int> rt;
        try{
            rt.push_back(valueX.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getX(). ";
        }
        return rt;
}
vector<double> Patient :: getY(){  return valueY;  }
vector<double> Patient :: getY(int i)
{
    vector<double> rt;
        try{
            rt.push_back(valueY.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getY(). ";
        }
        return rt;
    }
vector<int> Patient :: getDataType(){  return type;    }
vector<int> Patient :: getDataType(int i){
        vector<int> rt;
        try{
            rt.push_back(type.at(i));
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getDataType(). ";
        }
        return rt;
    }
int Patient :: getSizeAction(){    return action.size();   }
int Patient :: getSizeX(){ return valueX.size();   }
int Patient :: getSizeY(){ return valueY.size();   }
void Patient :: summary(){
        cout<<"Patient ID: "<< patientID<<endl;
        cout<<getSizeAction()<<" Action (A): ";print1DVector(action);
        cout<<getSizeY()<<" Reward (Y): ";print1DVector(valueY);
        cout<<getSizeX()<<" Covariate (X); ";print1DVector(valueX);
        cout<<"Covariate type: ";print1DVector(type);
//        for(auto t : type){
//                cout<<getEnumType(dataType(t))<<' ';
//        }
//        cout<<'\n';
    }


vector<Patient> creatPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<string> patientID){
    vector<Patient> patients;
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
        patients.push_back(Patient(patientID.at(j), action , valueX ,valueY , varType));
    }
    return patients;
}


void printPatientsX(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()
            <<" \tValue of X: ";
        print1DVector(patient.getX());
        cout<<endl;
    }
    cout<<endl;
}

void printPatientsXA(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()
            <<"\tValue of X: ";
        print1DVector(patient.getX());
        cout<<"\tAction: ";
        print1DVector(patient.getAction());
        cout<<endl;
    }
    cout<<endl;
}

void printPatients(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<"Patient ID: "<<patient.getPatientID()<<endl;
        cout<<"Value of Y: ";
        print1DVector(patient.getY());
        cout<<"\tAction: ";
        print1DVector(patient.getAction());
        cout<<"\tValue of X: ";
        print1DVector(patient.getX());
        cout<<endl;
    }
    cout<<endl;
}

