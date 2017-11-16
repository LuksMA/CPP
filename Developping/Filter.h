#ifndef FILTER _H
#define FILTER _H


class Filter
{
    public:
        virtual vector<Patient> meetCriteria(vector<Patient> patients)=0;


};

#endif
