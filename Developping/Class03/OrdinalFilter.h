#ifndef ORDINALFILTER_H
#define ORDINALFILTER_H

#include "Filter.h"

class OrdinalFilter : public Filter
{
    vector<int> myIndex;

    public:
        //constructor
        OrdinalFilter(vector<int> index);
        //destructor
        ~OrdinalFilter();

        pair <vector<Patient>,vector<Patient>> meetCriteria(pair<vector<Patient> , vector<Patient>> groupPatient);

};

#endif
