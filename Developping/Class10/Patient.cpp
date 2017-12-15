#include "Patient.h"



Patient :: Patient(short ID, vector<short> const &a, vector<short> &X, vector<float> &Y, vector<short> const &t)
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

short Patient :: getID()
{
    return patientID;
}
vector<short> Patient :: getAction()
{
    return action;
}
short Patient :: getAction(short i)
{
    return action[i];
}

vector<short> Patient :: getX()
{
    return valueX;
}
short Patient :: getX(short i)
{
    return valueX[i];
}


vector<float> Patient :: getY()
{
    return valueY;
}
float Patient :: getY(short i)
{
    return valueY[i];
}


vector<short> Patient :: getDataType()
{
    return type;
}
short Patient :: getDataType(short i)
{
    return type[i];
}
short Patient :: getSizeAction()
{
    return action.size();
}
short Patient :: getSizeX()
{
    return valueX.size();
}
short Patient :: getSizeY()
{
    return valueY.size();
}


float * Patient :: getYPtr(){
    return yArray;
}

bool Patient :: criteria(short varNo, short cutNo)
{
    if(valueX[varNo] < cutNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

short Patient :: criteriaInt(short varNo, short cutNo)
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

bool Patient :: criteriaAction()
{
    if(action[0] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

short Patient :: criteriaActionInt()
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

bitset<4> Patient :: criteria(short var1, short cut1, short var2, short cut2, short var3, short cut3){
    bitset<4> bitOut;
    bitOut[0] = criteriaInt(var1,cut1);
    bitOut[1] = criteriaInt(var2,cut2);
    bitOut[2] = criteriaInt(var3,cut3);
    bitOut[3] = actionBool;
    return bitOut;
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
