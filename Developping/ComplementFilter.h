#ifndef COMPLEMENTFILTER_H
#define COMPLEMENTFILTER_H

#include "Filter.h"

class ComplementFilter : public Filter
{
    vector<string> patientID;

    public:
        ComplementFilter(vector<string> id);
        ~ComplementFilter();
        vector<Patient> meetCriteria(vector<Patient> patients);

};

#endif // COMPLEMENTFILTER_H
