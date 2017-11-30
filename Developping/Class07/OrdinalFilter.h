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

        vector<Patient *> meetCriteria(vector<Patient *> patients);

    private:
        int getPatientX( Patient * p, int i);

};

#endif
