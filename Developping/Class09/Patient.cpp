#include "Patient.h"



Patient :: Patient(int ID, vector<int> const &a, vector<int> const &X, vector<double> const &Y, vector<int> const &t)
{
    patientID = ID;
    action = a;
    valueX = X;
    valueY = Y;
    type = t;
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

bool Patient :: criteria(int varNo, int cutNo, VariableInfo *v)
{
    if(type[varNo] != 2)
    {
        if(valueX[varNo] < cutNo)
        {
            return true;
        }
        else
        {
            return false;
        }
    }else{
        vector<int> subSet(v->getNominalCut(cutNo));
        if(find(subSet.begin(),subSet.end(),valueX[varNo]) != subSet.end()){
            return true;
        }else{
            return false;
        }
    }

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
