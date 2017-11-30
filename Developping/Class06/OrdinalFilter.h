#ifndef ORDINALFILTER_H
#define ORDINALFILTER_H

#include "Filter.h"

class OrdinalFilter : public Filter
{
//    unordered_map<int,int>  myIndex;
    int varNo;
    int cut;

    public:
        //constructor
        OrdinalFilter(int c, int no);
        //destructor
        ~OrdinalFilter();

        vector<Patient *> meetCriteria(vector<Patient *> patients);

};

#endif
