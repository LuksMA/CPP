#ifndef DATAGENERATION_H
#define DATAGENERATION_H

using namespace std;

class DataGeneration
{
    private:
        /// Settings for generate data
        int sampleSize;
        int covariateSize;

        vector<int> varType; // 0 for cont, 1 for ordinal, 2 for nominal
        vector<double> rangesY;
        vector<int> rangesActions;
        vector<double> rangesCont;
        vector<int> rangesOrd;
        vector<int> rangesNom;

        /// Generated raw data
        vector<int> id;
        vector<vector<double>> varY;
        vector<vector<int>> actions;
        vector<vector<double>> varCont;
        vector<vector<int>> varOrd;
        vector<vector<int>> varNom;

         /// Processed data
        vector<vector<int>> varContInt;
        vector<vector<int>> dataSet;


    public:
        DataGeneration(vector<int> vType, vector<double> rY, vector<int> rActions, vector<double> rCont, vector<int> rOrd, vector<int> rNom);
        void creatSamples(int sSize);
        void preprocessing();
        vector<vector<int>> combineData(vector<vector<int>> varCont, vector<vector<int>> varOrd, vector<vector<int>> varNom);

        int getSampleSize();
        int getCovariateSize();
        int getYSize();
        int getActionSize();
        int getContVarSize();
        int getOrdVarSize();
        int getNomVarSize();

        vector<int> getVarType();
        vector<vector<double>> getY();
        vector<vector<int>> getActions();
        vector<vector<double>> getVarCont();
        vector<vector<int>> getVarCont(int i);
        vector<vector<int>> getVarOrd();
        vector<vector<int>> getVarNom();
        vector<vector<int>> getDataSet();
        vector<int> getID();

        void printY();
        void printAction();
        void printContVar();
        void printContVar(int i);
        void printOrdVar();
        void printNomVar();
        void printDataSet();
        void printInfo(int i);
        void genReport();

    private:
        vector<int> patientID(int noSample);
        template<class T> int getRangeSize(vector<T> vectIn);
        vector<int> createSeed(int varsize, int start);

        vector<vector<int>> assignSeed(vector<int> seed, vector<int> varType);
        double dataGenerator(unsigned seed, double lowerBound, double upperBound);
        int dataGenerator(unsigned seed, int nMin, int nMax);
        vector<vector<double>> sampleGenerator(vector<int> seed, vector<double> ranges);
        vector<vector<int>> sampleGenerator(vector<int> seed, vector<int> ranges);

        vector<int> percentileVec(vector<double> &vectIn);
        vector<vector<int>> percentileVec(vector<vector<double>> &vectIn);
        map<double, int> percentileMap(vector<double> &vectorIn);
        double percentile(double len,double index);
        int assignPercentile(double p);

        template<class T>   void print1DVector(vector<T> const &vectIn);
        template<class T>   void print2DVector(vector<vector<T>> const &vectIn);
};

#endif // DATAGENERATION_H
