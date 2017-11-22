#ifndef ACTIONFILTER_H
#define ACTIONFILTER_H

#include "Filter.h"

class ActionFilter : public Filter
{
    vector<int> myAction;
    double sum;

    public:
        //constructor
        ActionFilter(vector<int> index);
        //destructor
        ~ActionFilter();

        vector<Patient> meetCriteria(vector<Patient> patients);
        double getSum();
        void resetSum();
};

#endif // ACTIONFILTER_H
