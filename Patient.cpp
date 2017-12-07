#include "Patient.h"



Patient :: Patient(int ID, vector<int> const &a, vector<int> &X, vector<double> const &Y, vector<int> const &t)
{
    patientID = ID;
    action = a;
    valueX = X;
    valueY = Y;
    type = t;
    y = Y[0];
    actionBool = criteriaActionInt();
    xArray = &X[0];
}



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

//bool Patient :: criteria(int varNo, int cutNo, VariableInfo *v)
//{
//    if(type[varNo] != 2)
//    {
//        if(valueX[varNo] < cutNo)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        vector<int> subSet(v->getNominalCut(cutNo));
//        if(find(subSet.begin(),subSet.end(),valueX[varNo]) != subSet.end())
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//}

bool Patient :: criteria(int varNo, int cutNo)
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

bitset<4> Patient :: criteria(int var1, int cut1, int var2, int cut2, int var3, int cut3){
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
