#include "AllFilter.h"

void AllFilter :: addFilter(Filter &A)
{
    criterias.push_back(&A);
}

void AllFilter :: clearAllFilter(){
        criterias.clear();
}

pair <vector<Patient>,vector<Patient>> AllFilter :: meetCriteria(pair<vector<Patient>,vector<Patient>> patients){
        pair <vector<Patient>,vector<Patient>>  before = patients;
        pair <vector<Patient>,vector<Patient>>  after;
        for(auto cr: criterias){
            pair <vector<Patient>,vector<Patient>> after = cr -> meetCriteria(before);
            before = after;
        }
        return before;
    }
