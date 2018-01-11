#include "Patient.h"

Patient :: Patient(int ID, vector<int> const &a, vector<int> &X, vector<double> &Y, vector<int> const &t)
{
    patientID = ID;
    action = a;
    valueX = X;
    valueY = Y;
    type = t;
    actionBool = criteriaActionInt();
    xArray = &X[0];
    yArray = &Y[0];
}

Patient :: ~Patient(){}

int Patient :: getID()
{
    return patientID;
}
vector<int> Patient :: getAction()
{
    return action;
}
int Patient :: getAction(int i)
{
    return action[i];
}

vector<int> Patient :: getX()
{
    return valueX;
}
int Patient :: getX(int i)
{
    return valueX[i];
}


vector<double> Patient :: getY()
{
    return valueY;
}
double Patient :: getY(int i)
{
    return valueY[i];
}


vector<int> Patient :: getDataType()
{
    return type;
}
int Patient :: getDataType(int i)
{
    return type[i];
}
int Patient :: getSizeAction()
{
    return action.size();
}
int Patient :: getSizeX()
{
    return valueX.size();
}
int Patient :: getSizeY()
{
    return valueY.size();
}



int Patient :: criteriaInt(int varNo, int cutNo, DataInfo* di){
    if(di->nomContains(xArray[varNo],cutNo)){
        return 1;
    }else{
        return 0;
    }
}

int Patient :: criteriaInt(int varNo, int cutNo)
{
    if(xArray[varNo] < cutNo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int Patient :: criteriaActionInt()
{
    if(action[0] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Patient :: criteria(int var1, int cut1, int var2, int cut2, int var3, int cut3){
    return 8*criteriaInt(var1,cut1) + 4*criteriaInt(var2,cut2) + 2*criteriaInt(var3,cut3) + actionBool;
}

int Patient :: criteria(int var1, int cut1, int var2, int cut2, int var3, int cut3, DataInfo* d3){
    return 8*criteriaInt(var1,cut1) + 4*criteriaInt(var2,cut2) + 2*criteriaInt(var3,cut3,d3) + actionBool;
}

int Patient :: criteria(int var1, int cut1, int var2, int cut2, DataInfo* d2, int var3, int cut3, DataInfo* d3){
    return 8*criteriaInt(var1,cut1) + 4*criteriaInt(var2,cut2,d2) + 2*criteriaInt(var3,cut3,d3) + actionBool;
}

int Patient :: criteria(int var1, int cut1, DataInfo* d1, int var2, int cut2, DataInfo* d2, int var3, int cut3, DataInfo* d3){
    return 8*criteriaInt(var1,cut1,d1) + 4*criteriaInt(var2,cut2,d2) + 2*criteriaInt(var3,cut3,d3) + actionBool;
}

void Patient :: summary()
{
    cout<<"Patient ID: "<< patientID<<endl;
    cout<<getSizeAction()<<" Action (A): ";
    print1DVector(action);
    cout<<'\t'<<getSizeY()<<" Reward (Y): ";
    print1DVector(valueY);
    cout<<'\n'<<getSizeX()<<" Covariate (X); ";
    print1DVector(valueX);
    cout<<"\nCovariate type: ";
    print1DVector(type);
}


/// Print Individual Patient
void Patient :: printPatientID() {
    cout<<"ID:"<<patientID;
}
void Patient :: printPatientX() {
    cout<<"X:";
    print1DVector(valueX);
}
void Patient :: printPatientAction(){
    cout<<"A:";
    print1DVector(action);
}

void Patient :: printPatientY(){
    cout<<"Y:";
    print1DVector(valueY);
}

void Patient :: printPatientsX(){
    printPatientID();
    cout<<' ';
    printPatientX();
    cout<<endl;
}

void Patient :: printPatientsXA(){
    printPatientID();
    cout<<' ';
    printPatientX();
    cout<<' ';
    printPatientAction();
    cout<<endl;
}

void Patient :: printPatients(){
    printPatientID();
    cout<<' ';
    printPatientX();
    cout<<' ';
    printPatientAction();
    cout<<' ';
    printPatientY();
    cout<<endl;
}

template<class T>
void Patient :: print1DVector(vector<T> const &vectIn)
{
    cout<<"[ ";
    for(const auto &row : vectIn)
    {
        cout<<row<<' ';
    }
    cout<<']';
}
