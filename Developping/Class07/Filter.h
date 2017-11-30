#ifndef FILTER_H
#define FILTER_H

#include "Patient.h"
#include <vector>
using namespace std;

class Filter
{
    public:
        virtual vector<Patient *> meetCriteria(vector<Patient *> patients)=0;

};

#endif
