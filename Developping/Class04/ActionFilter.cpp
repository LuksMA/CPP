#include "ActionFilter.h"

ActionFilter :: ActionFilter(vector<int> index)
{
    myAction = index;
}
ActionFilter :: ~ActionFilter(){  }

pair <vector<Patient>,vector<Patient>> ActionFilter :: meetCriteria(pair <vector<Patient>,vector<Patient>> groupPatient){
    pair <vector<Patient>,vector<Patient>> pairOut;
    vector<Patient> vectSelected;vectSelected.empty();
    vector<Patient> vectUnSelected; vectUnSelected.empty();
    for(auto patient : groupPatient.first){
        if(patient.getAction() == myAction){
            vectSelected.push_back(patient);
        }
    }
    for(auto patient : groupPatient.second){
        if(patient.getAction() != myAction){
            vectUnSelected.push_back(patient);
        }
    }
    pairOut = make_pair(vectSelected,vectUnSelected);
    return pairOut;
}
