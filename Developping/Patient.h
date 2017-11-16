#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <string>
using namespace std;

class Patient
{
    private:
        string patientID;
        vector<int> action;
        vector<int> valueX;
        vector<double> valueY;
        vector<int> type;

    public:
        Patient(string ID, vector<int> a, vector<int> X, vector<double> Y, vector<int> t);

        string getPatientID();
        vector<int> getAction();
        vector<int> getAction(int i);
        vector<int> getX();
        vector<int> getX(int i);
        vector<double> getY();
        vector<double> getY(int i);
        vector<int> getDataType();
        vector<int> getDataType(int i);
        int getSizeAction();
        int getSizeX();
        int getSizeY();
        void summary();


};

#endif // PATIENT_H
