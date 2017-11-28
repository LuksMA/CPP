#ifndef ACTIONFILTER_H
#define ACTIONFILTER_H

#include "Filter.h"

class ActionFilter : public Filter
{
    vector<int> myAction;
    double sumT1;
    double sumT0;

    public:
        //constructor
        ActionFilter(vector<int> index);
        //destructor
        ~ActionFilter();

        vector<Patient *> meetCriteria(vector<Patient *> patients);;
        double getSumT0();
        double getSumT1();
        void resetSum();
};

#endif // ACTIONFILTER_H
