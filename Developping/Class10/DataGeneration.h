#ifndef DATAGENERATION_H
#define DATAGENERATION_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

class DataGeneration
{
    private:
        /// Settings for generate data
        short sampleSize;
        short covariateSize;

        vector<short> varType; // 0 for cont, 1 for ordinal, 2 for nominal
        vector<float> rangesY;
        vector<short> rangesActions;
        vector<float> rangesCont;
        vector<short> rangesOrd;
        vector<short> rangesNom;

        /// Generated raw data
        vector<short> id;
        vector<vector<float>> varY;
        vector<vector<short>> actions;
        vector<vector<float>> varCont;
        vector<vector<short>> varOrd;
        vector<vector<short>> varNom;

         /// Processed data
        vector<vector<short>> varContInt;
        vector<vector<short>> dataSet;
        float sumTreatment0;

    public:
        DataGeneration(vector<short> const &vType, vector<float> const &rY, vector<short> const &rActions, vector<float> const &rCont, vector<short> const &rOrd, vector<short> const &rNom);
        ~DataGeneration();
        void creatSamples(short sSize);
        void preprocessing();
        vector<vector<short>> combineData(vector<vector<short>> const &varCont, vector<vector<short>> const &varOrd, vector<vector<short>> const &varNom);

        int getSampleSize();
        int getCovariateSize();
        int getYSize();
        int getActionSize();
        int getContVarSize();
        int getOrdVarSize();
        int getNomVarSize();

        vector<short> getVarType();
        vector<vector<float>> getY();
        vector<vector<short>> getActions();
        vector<vector<float>> getVarCont();
        vector<vector<short>> getVarCont(short i);
        vector<vector<short>> getVarOrd();
        vector<vector<short>> getVarNom();
        vector<vector<short>> getDataSet();
        vector<short> getID();
        float getSumT0();

        void printY();
        void printAction();
        void printContVar();
        void printContVar(short i);
        void printOrdVar();
        void printNomVar();
        void printDataSet();
        void printInfo(short i);
        void genReport();

    private:
        vector<short> patientID(short noSample);
        template<class T> int getRangeSize(vector<T> const &vectIn);
        vector<short> createSeed(short varsize, short start);

        vector<vector<short>> assignSeed(vector<short> const &seed, vector<short> const &varType);
        float dataGenerator(short seed, float lowerBound, float upperBound);
        short dataGenerator(short seed, short nMin, short nMax);
        vector<vector<float>> sampleGenerator(vector<short> const &seed, vector<float> const &ranges);
        vector<vector<short>> sampleGenerator(vector<short> const &seed, vector<short> const &ranges);

        vector<short> percentileVec(vector<float> const &vectIn);
        vector<vector<short>> percentileVec(vector<vector<float>> const &vectIn);
        map<float, short> percentileMap(vector<float> const &vectorIn);
        float percentile(float len,float index);
        short assignPercentile(float p);

        void sumTreatmentCal();

        template<class T>   void print1DVector(vector<T> const &vectIn);
        template<class T>   void print2DVector(vector<vector<T>> const &vectIn);
};

#endif // DATAGENERATION_H

