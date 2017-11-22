#include <vector>
#include <map>
#include <string>
#include "Patient.h"
#include "Print.cpp"

using namespace std;

Patient :: Patient(int ID, vector<int> a, vector<int> X, vector<double> Y, vector<int> t)
{
    patientID = ID;
    action = a;
    valueX = X;
    valueY = Y;
    type = t;
}

int Patient :: getID(){  return patientID;   }
vector<int> Patient :: getAction(){  return action;  }
int Patient :: getAction(int i)
{
        int rt;
        try{
            rt = action.at(i);
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getAction(). ";
        }
        return rt;
 }
vector<int> Patient :: getX(){ return valueX;  }
int Patient :: getX(int i)
{
        int rt;
        try{
            rt = valueX.at(i);
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getX(). ";
        }
        return rt;
}
vector<double> Patient :: getY(){  return valueY;  }
double Patient :: getY(int i)
{
    double rt;
        try{
            rt = valueY.at(i);
        }catch (const std::out_of_range& oor) {
            cerr << "Out of range error. No return for getY(). ";
        }
        return rt;
    }
vector<int> Patient :: getDataType(){  return type;    }
int Patient :: getDataType(int i){
        int rt;
        try{
            rt = type.at(i);
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
        cout<<'\t'<<getSizeY()<<" Reward (Y): ";print1DVector(valueY);
        cout<<'\n'<<getSizeX()<<" Covariate (X); ";print1DVector(valueX);
        cout<<"\nCovariate type: ";print1DVector(type);
//        for(auto t : type){
//                cout<<getEnumType(dataType(t))<<' ';
//        }
//        cout<<'\n';
    }


vector<Patient> creatPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<int> patientID){
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
        cout<<"Patient ID: "<<patient.getID()
            <<" \tValue of X: ";
        print1DVector(patient.getX());
        cout<<endl;
    }
    cout<<endl;
}

void printPatientsXA(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<patient.getID()
            <<"\tX: ";
        print1DVector(patient.getX());
        cout<<"\tAction: ";
        print1DVector(patient.getAction());
        cout<<endl;
    }
    cout<<endl;
}

void printPatients(vector<Patient> patients){
    for(auto& patient : patients){
        cout<<patient.getID()
            <<"\tX: ";
        print1DVector(patient.getX());
        cout<<"\tAction: ";
        print1DVector(patient.getAction());
        cout<<"\tY: ";
        print1DVector(patient.getY());
        cout<<endl;
    }
    cout<<endl;
}


vector<Patient> combinePatients(vector<Patient> p1, vector<Patient> p2){
    p1.insert( p1.end(), p2.begin(), p2.end() );
    return p1;
}


double expect(vector<Patient> patients, int s){
    double out = 0;
    for(auto patient : patients){
        out = out + patient.getY(0);
    }
    return out*2/s;
}
