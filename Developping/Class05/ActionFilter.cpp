#include "ActionFilter.h"

ActionFilter :: ActionFilter(vector<int> index)
{
    myAction = index;
    sum = 0.0;
}
ActionFilter :: ~ActionFilter(){  }

vector<Patient> ActionFilter :: meetCriteria(vector<Patient> patients){
    vector<Patient> vectOut;
    for(auto patient : patients){
        if(patient.getAction() == myAction){
            vectOut.push_back(patient);
            sum += patient.getY().at(0);
        }
    }
    return vectOut;
}

double ActionFilter :: getSum(){
    return sum;
}
