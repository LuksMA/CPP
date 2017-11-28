#ifndef NOMINALFILTER_H
#define NOMINALFILTER_H

#include "Filter.h"

class NominalFilter : public Filter
{
    vector<int> myIndex;

    public:
        //constructor
        NominalFilter(vector<int> index);
        //destructor
        ~NominalFilter();

        vector<Patient *> meetCriteria(vector<Patient *> patients);
};

#endif // NOMINALFILTER_H
