#include "OrdinalFilter.h"

OrdinalFilter :: OrdinalFilter(vector<int> index)
{
    myIndex = index;
}
OrdinalFilter :: ~OrdinalFilter(){}



vector<Patient *> OrdinalFilter :: meetCriteria(vector<Patient *> patients){
    vector<Patient *> vectOut;
    vectOut.reserve(3000);
    int varNo = myIndex.at(0);
    int cut = myIndex.at(1);
    int dir = myIndex.at(2);

    switch(dir){
        case 1:
            for(auto p : patients){
                if(getPatientX(p,varNo) >= cut)
                    vectOut.push_back(p);
                };break;
        case -1:
            for(auto p : patients){
                if(getPatientX(p,varNo) < cut)
                    vectOut.push_back(p);
                };break;
        default:
            cout<<"Wrong direction input for ordinal filter.";
        }
    return vectOut;
}
