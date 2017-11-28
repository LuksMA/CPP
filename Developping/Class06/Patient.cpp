#include <vector>
#include <map>
#include <string>
#include "Patient.h"
#include "Print.cpp"
#include "Patients.cpp"

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

