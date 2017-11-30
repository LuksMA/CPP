#ifndef NOMINALFILTER_H
#define NOMINALFILTER_H

#include "Filter.h"

class NominalFilter : public Filter
{
    vector<int> myIndex;
    int varNo;

    public:
        //constructor
        NominalFilter(vector<int> index, int varNo);
        //destructor
        ~NominalFilter();

        vector<Patient *> meetCriteria(vector<Patient *> patients);
};

#endif // NOMINALFILTER_H
