#include "ActionFilter.h"

ActionFilter :: ActionFilter(vector<int> index)
{
    myAction = index;
}
ActionFilter :: ~ActionFilter(){  }

vector<Patient> ActionFilter :: meetCriteria(vector<Patient> patients){
    vector<Patient> vectOut;
    for(auto patient : patients){
        if(patient.getAction() == myAction){
            vectOut.push_back(patient);
        }
    }
    return vectOut;
}
