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
        after.reserve(3000);
        for(auto cr: criterias){
            if(!before.empty()){
               vector<Patient *> after = cr -> meetCriteria(before);
               before = after;
            }else{
               break;
            }
        }
        return before;
    }
