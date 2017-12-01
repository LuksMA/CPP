#include "OrdinalFilter.h"

OrdinalFilter :: OrdinalFilter(int c, int no, int d)
{
    cut = c;
    varNo = no;
    direction = d;
}
OrdinalFilter :: ~OrdinalFilter(){}



vector<Patient *> OrdinalFilter :: meetCriteria(vector<Patient *> patients){
    vector<Patient *> vectOut;
    vectOut.reserve(3000);
    if(direction == -1){
        for(auto p : patients){
            if(getPatientX(p,varNo) < cut)
                vectOut.push_back(p);
        }
    }else if(direction == 1){
        for(auto p : patients){
            if(getPatientX(p,varNo) >= cut)
                vectOut.push_back(p);
        }
    }else{
        cout<<"Incorrect direction input for Ordinal Filter.\n";
    }

    return vectOut;
}

int OrdinalFilter :: getPatientX( Patient * p, int i){
    return p->getX(i);
}
