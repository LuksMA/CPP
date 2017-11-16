#include "NominalFilter.h"

NominalFilter::NominalFilter(vector<int> index)
{
    myIndex = index;
}
NominalFilter :: ~NominalFilter(){}

pair <vector<Patient>,vector<Patient>> NominalFilter :: meetCriteria(pair<vector<Patient> , vector<Patient>> groupPatient){
    pair <vector<Patient>,vector<Patient>> pairOut;
    vector<Patient> vectSelected;vectSelected.empty();
    vector<Patient> vectUnSelected;vectUnSelected.empty();

    int varNo = myIndex.at(0);
    int combNo = myIndex.at(1);
    vector<int> subSet(myIndex.begin()+2,myIndex.end());
    for(auto patient : groupPatient.first){
        if(find(subSet.begin(), subSet.end(), patient.getX(varNo).at(0)) != subSet.end()){
            vectSelected.push_back(patient);
        }else{
            vectUnSelected.push_back(patient);
        }
    }
    pairOut = make_pair(vectSelected,combinePatients(groupPatient.second, vectUnSelected));
    return pairOut;
}
