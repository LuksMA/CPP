#include "OrdinalFilter.h"

OrdinalFilter :: OrdinalFilter(int c, int no)
{
    cut = c;
    varNo = no;

}
OrdinalFilter :: ~OrdinalFilter(){}



vector<Patient *> OrdinalFilter :: meetCriteria(vector<Patient *> patients){
    vector<Patient *> vectOut;
    vectOut.reserve(3000);
    for(auto p : patients){
        if(getPatientX(p,varNo) < cut)
            vectOut.push_back(p);
    }
    return vectOut;
}
