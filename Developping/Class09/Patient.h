#ifndef PATIENT_H
#define PATIENT_H

#include "VariableInfo.h"

#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>

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
        Patient(int ID, vector<int> const &a, vector<int> const &X, vector<double> const &Y, vector<int> const &t);
        ~Patient();

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
        bool criteria(int varNo, int cutNo, VariableInfo *v);

    private:
        template<class T> void print1DVector(vector<T> const &vectIn);
};

#endif // PATIENT_H
