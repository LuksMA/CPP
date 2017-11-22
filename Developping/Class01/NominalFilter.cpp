#include "NominalFilter.h"

NominalFilter::NominalFilter(vector<int> index)
{
    myIndex = index;
}
NominalFilter :: ~NominalFilter(){}

vector<Patient> NominalFilter :: meetCriteria(vector<Patient> patients){
    vector<Patient> vectOut;
    int varNo = myIndex.at(0);
    int combNo = myIndex.at(1);
    vector<int> subSet(myIndex.begin()+2,myIndex.end());
    for(auto patient : patients){
        if(find(subSet.begin(), subSet.end(), patient.getX(varNo)) != subSet.end()){
            vectOut.push_back(patient);
        }
    }
    return vectOut;
}
