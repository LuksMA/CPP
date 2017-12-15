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
        void printPatients();
        void printPatientsX();
        void printPatientsXA();

    private:
        vector<Patient *> createPatients(vector<vector<int>> dataSet,vector<vector<int>> actions, vector<vector<double>> Y,vector<int> varType, vector<int> patientID);

};

#endif // PATIENTDATA_H
