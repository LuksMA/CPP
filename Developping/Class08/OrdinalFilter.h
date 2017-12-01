#ifndef ORDINALFILTER_H
#define ORDINALFILTER_H

#include "Filter.h"

class OrdinalFilter : public Filter
{
    int varNo;
    int cut;
    int direction;

    public:
        //constructor
        OrdinalFilter(int c, int no, int d);
        //destructor
        ~OrdinalFilter();

        vector<Patient *> meetCriteria(vector<Patient *> patients);

    private:
        int getPatientX( Patient * p, int i);

};

#endif
