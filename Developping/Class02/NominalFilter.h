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

        pair <vector<Patient>,vector<Patient>> meetCriteria(pair<vector<Patient> , vector<Patient>> groupPatient);
};

#endif // NOMINALFILTER_H
