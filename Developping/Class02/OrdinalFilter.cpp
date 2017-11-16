#include "OrdinalFilter.h"

OrdinalFilter :: OrdinalFilter(vector<int> index)
{
    myIndex = index;
}
OrdinalFilter :: ~OrdinalFilter(){}

pair <vector<Patient>,vector<Patient>> OrdinalFilter :: meetCriteria(pair<vector<Patient> , vector<Patient>> groupPatient){
    pair <vector<Patient>,vector<Patient>> pairOut;
    vector<Patient> vectSelected;vectSelected.empty();
    vector<Patient> vectUnSelected;vectUnSelected.empty();
    int varNo = myIndex.at(0);
    int cut = myIndex.at(1);
    int dir = myIndex.at(2);

    switch(dir){
        case 1:
            for(auto patient : groupPatient.first){
                if(patient.getX(varNo).at(0) >= cut){
                    vectSelected.push_back(patient);
                }else{
                    vectUnSelected.push_back(patient);
                }
            }
            break;
        case -1:
            for(auto patient : groupPatient.first){
                if(patient.getX(varNo).at(0) < cut){
                    vectSelected.push_back(patient);
                }else{
                    vectUnSelected.push_back(patient);
                }
            }
            break;
        default:
            cout<<"Wrong direction input.";
        }

    pairOut = make_pair(vectSelected,combinePatients(groupPatient.second, vectUnSelected));
    return pairOut;
}
