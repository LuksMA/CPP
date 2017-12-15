#ifndef PATIENT_H
#define PATIENT_H

//#include "VariableInfo.h"

#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class Patient
{
    private:
        int patientID;
        vector<int> action;
        vector<int> valueX;
        vector<double> valueY;
        vector<int> type;
        int actionBool;
        int *xArray;
        double *yArray;

    public:
        Patient(int ID, vector<int> const &a, vector<int> &X, vector<double> &Y, vector<int> const &t);
        ~Patient();


        int getID();
        vector<int> getAction();
        int getAction(int i);
        vector<int> getX();
        int getX(int i);
        vector<double> getY();
        double getY(int i);
        double *getYPtr();

        vector<int> getDataType();
        int getDataType(int i);
        int getSizeAction();
        int getSizeX();
        int getSizeY();
        void summary();

        bool criteriaAction();
        int criteriaActionInt();
        bitset<4> criteria(int var1, int cut1, int var2, int cut2, int var3, int cut3);

        void printPatientID();
        void printPatientX();
        void printPatientAction();
        void printPatientY();
        void printPatients();
        void printPatientsX();
        void printPatientsXA();

    private:
        template<class T> void print1DVector(vector<T> const &vectIn);
        bool criteria(int varNo, int cutNo);
        int criteriaInt(int varNo, int cutNo);

};

#endif // PATIENT_H
