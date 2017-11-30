#ifndef VARIABLEINFO_H
#define VARIABLEINFO_H
#include <unordered_map>

class VariableInfo
{
    private:
        int varNo;
        int varType;
        unordered_map<int,int> cuts;
        map<vector<int>, vector<int>> searchSets;

    public:
        VariableInfo(int no, int type, vector<int> dataSetColumn);
        int getCombSize();
        int getVarNo();
        int getVarType();
        unordered_map<int,int> getCuts();
        map<vector<int>, vector<int>> getCombs();
        vector<int> getComb(vector<int> vectIn);
        void getCombPrint(vector<int> vectIn);
        void printVarInfo();
        void printCuts();

    private:
        unordered_map<int,int> seq(int n);
};

#endif // VARIABLEINFO_H
