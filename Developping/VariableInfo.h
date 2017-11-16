#ifndef VARIABLEINFO_H
#define VARIABLEINFO_H


class VariableInfo
{
    private:
        int varNo;
        int varType;
        map<vector<int>, vector<int>> searchSets;
    public:
        VariableInfo(int no, int type, vector<int> dataSetColumn);
        int getCombSize();
        int getVarNo();
        int getVarType();
        map<vector<int>, vector<int>> getCombs();
        vector<int> getComb(vector<int> vectIn);
        void getCombPrint(vector<int> vectIn);
        void printVarInfo();
    private:

};

#endif // VARIABLEINFO_H
