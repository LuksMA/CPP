#ifndef VARIABLEINFO_H
#define VARIABLEINFO_H

#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class VariableInfo
{

    private:
        int varNo;
        int varType;
        map<vector<int>, vector<int>> searchSets;
        enum dataType { cont,    ord,    nomi   };
        vector<int> cuts;

    public:
        VariableInfo(int no, int type, vector<int> &dataSetColumn);
        ~VariableInfo();

        int getVarNo();
        int getVarType();
        int getCombSize();
        vector<int> getComb(vector<int> vectIn);
        map<vector<int>, vector<int>> getCombs();
        vector<int> getCuts();

        void printVarInfo();
        void printComb(vector<int> &vectIn);


    private:
        vector<int> uniqueValues(vector<int> &vectorIn);
        template<class T> map<vector<int>,vector<T>> mapSubsets(vector<T> &set, int varN);
        map<vector<int>, vector<int>> mapSequence(vector<int> &vectIn, int varNum);
        int flip(int i);
        template<class T>   void printNominalMap(map<vector<int>,vector<T>> &mapIn);
        template<class T>   void printOrdinalMap(map<vector<int>,vector<T>> &mapIn);
        template<class T>   void print1DVector(vector<T> const &vectIn);
        string getEnumType(dataType);

};

#endif // VARIABLEINFO_H
