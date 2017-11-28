#include "AllFilter.h"

void AllFilter :: addFilter(Filter &A)
{
    criterias.push_back(&A);
}

void AllFilter :: clearAllFilter(){
        criterias.clear();
}

vector<Patient *> AllFilter :: meetCriteria(vector<Patient *> patients){
        vector<Patient *> before(patients);
        vector<Patient *> after;
        for(auto cr: criterias){
            vector<Patient *> after = cr -> meetCriteria(before);
            before = after;
        }
        return before;
    }
