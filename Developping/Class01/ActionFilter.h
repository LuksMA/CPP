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

        vector<Patient> meetCriteria(vector<Patient> patients);
};

#endif // ACTIONFILTER_H
