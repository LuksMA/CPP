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
        short patientID;
        vector<short> action;
        vector<short> valueX;
        vector<float> valueY;
        vector<short> type;
        short actionBool;
        short *xArray;
        float *yArray;

    public:
        Patient(short ID, vector<short> const &a, vector<short> &X, vector<float> &Y, vector<short> const &t);
        ~Patient();


        short getID();
        vector<short> getAction();
        short getAction(short i);
        vector<short> getX();
        short getX(short i);
        vector<float> getY();
        float getY(short i);
        float *getYPtr();

        vector<short> getDataType();
        short getDataType(short i);
        short getSizeAction();
        short getSizeX();
        short getSizeY();
        void summary();

        bool criteriaAction();
        short criteriaActionInt();
        bitset<4> criteria(short var1, short cut1, short var2, short cut2, short var3, short cut3);

        void printPatientID();
        void printPatientX();
        void printPatientAction();
        void printPatientY();
        void printPatients();
        void printPatientsX();
        void printPatientsXA();


    private:
        template<class T> void print1DVector(vector<T> const &vectIn);
        bool criteria(short varNo, short cutNo);
        short criteriaInt(short varNo, short cutNo);

};

#endif // PATIENT_H
