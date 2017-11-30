#ifndef ACTIONFILTER_H
#define ACTIONFILTER_H

#include "Filter.h"
#include "Patient.h"
#include "PatientData.h"

class ActionFilter : public Filter
{
    vector<int> myAction;
    double sumT1;
    double sumT0;

    public:
        //constructor
        ActionFilter(vector<int> index);
        //destructor
        ~ActionFilter();

        vector<Patient *> meetCriteria(vector<Patient *> patients);;
        double getSumT0();
        double getSumT1();
        void resetSum();
    private:
        vector<int> getPatientAction( Patient * p );
        vector<double> getPatientY( Patient * p );
};

#endif // ACTIONFILTER_H
