#ifndef FILTER_H
#define FILTER_H

class Filter
{
    public:
        virtual pair<vector<Patient> , vector<Patient>> meetCriteria(pair<vector<Patient>,vector<Patient>> patients)=0;


};

#endif
