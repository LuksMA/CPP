#include "NominalFilter.h"

NominalFilter::NominalFilter(vector<int> index)
{
    myIndex = index;
}
NominalFilter :: ~NominalFilter(){}

vector<Patient *> NominalFilter :: meetCriteria(vector<Patient *> patients){
    vector<Patient *> vectOut;
    vectOut.reserve(3000);
    int varNo = myIndex.at(0);
    int combNo = myIndex.at(1);
    vector<int> subSet(myIndex.begin()+2,myIndex.end());
    for(auto p : patients){
        if(find(subSet.begin(), subSet.end(), getPatientX(p,varNo)) != subSet.end()){
            vectOut.push_back(p);
        }
    }
    return vectOut;
}
