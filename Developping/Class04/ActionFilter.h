#ifndef ACTIONFILTER_H
#define ACTIONFILTER_H

#include "Filter.h"

class ActionFilter : public Filter
{
    vector<int> myAction;

    public:
        //constructor
        ActionFilter(vector<int> index);
        //destructor
        ~ActionFilter();

        pair <vector<Patient>,vector<Patient>> meetCriteria(pair<vector<Patient> , vector<Patient>> groupPatient);
};

#endif // ACTIONFILTER_H
