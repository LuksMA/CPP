#include "ActionFilter.h"

ActionFilter :: ActionFilter(vector<int> index)
{
    myAction = index;
    sumT0 = 0.0;
    sumT1 = 0.0;
}
ActionFilter :: ~ActionFilter(){  }

vector<Patient *> ActionFilter :: meetCriteria(vector<Patient *> patients){
    vector<Patient *> vectOut;
    vectOut.reserve(3000);
    for(auto p : patients){
        if(getPatientAction(p) == myAction){
            vectOut.push_back(p);
            sumT1 += getPatientY(p)[0];
        }else{
            sumT0 += getPatientY(p)[0];
        }
    }
    return vectOut;
}

double ActionFilter :: getSumT0(){
    return sumT0;
}

double ActionFilter :: getSumT1(){
    return sumT1;
}


void ActionFilter :: resetSum(){
    sumT0 = 0.0;
    sumT1 = 0.0;
}
