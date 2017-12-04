#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include "Patient.h"
#include "DataGeneration.h"

#include <vector>

using namespace std;

class PatientData
{   private:
        vector<Patient *> patientsData;

    public:
        PatientData();
        PatientData(DataGeneration &data);
        PatientData(vector<Patient *> &dataSet);
        ~PatientData();

        vector<Patient *> getPatients();
        int getPatientX( Patient * p, int i);
        vector<int> getPatientAction( Patient * p );
        vector<double> getPatientY( Patient * p );

        void printPatientID( Patient * p );
        void printPatientX( Patient * p );
        void printPatientAction( Patient * p );
        void printPatientY( Patient * p );

//        void printPatientsX(vector<Patient *> const &patients);
//        void printPatientsXA(vector<Patient *> const &patients);
//        void printPatients(vector<Patient *> const &patients);

    private:
        vector<Patient *> createPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<int> patientID);
        template<class T> void print1DVector(vector<T> vectIn);
};

#endif // PATIENTDATA_H
