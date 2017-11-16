#include "OrdinalFilter.h"

OrdinalFilter :: OrdinalFilter(vector<int> index)
{
    myIndex = index;
}
OrdinalFilter :: ~OrdinalFilter(){}

vector<Patient> OrdinalFilter :: meetCriteria(vector<Patient> patients){
    vector<Patient> vectOut;
    int varNo = myIndex.at(0);
    int cut = myIndex.at(1);
    int dir = myIndex.at(2);

    switch(dir){
        case 1:
            for(auto patient : patients){
                if(patient.getX(varNo).at(0) >= cut)
                    vectOut.push_back(patient);
                };break;
        case -1:
            for(auto patient : patients){
                if(patient.getX(varNo).at(0) < cut)
                    vectOut.push_back(patient);
                };break;
        default:
            cout<<"Wrong direction input.";
        }
    return vectOut;
}
