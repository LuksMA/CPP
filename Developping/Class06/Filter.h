#ifndef FILTER_H
#define FILTER_H


class Filter
{
    public:
        virtual vector<Patient *> meetCriteria(vector<Patient *> patients)=0;


};

#endif
