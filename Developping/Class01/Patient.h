#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
using namespace std;

class Patient
{
    private:
        int patientID;
        vector<int> action;
        vector<int> valueX;
        vector<double> valueY;
        vector<int> type;

    public:
        Patient(int ID, vector<int> a, vector<int> X, vector<double> Y, vector<int> t);

        int getID();
        vector<int> getAction();
        int getAction(int i);
        vector<int> getX();
        int getX(int i);
        vector<double> getY();
        double getY(int i);
        vector<int> getDataType();
        int getDataType(int i);
        int getSizeAction();
        int getSizeX();
        int getSizeY();
        void summary();
};

#endif // PATIENT_H
