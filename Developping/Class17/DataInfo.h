#ifndef DATAINFO_H
#define DATAINFO_H

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class DataInfo
{
    private:
        int varNo;
        int varType;
        vector<int> range;
        vector<set<int>> nomCuts;

    public:
        DataInfo(void){};
        void load_DataInfo(int no, int type, vector<int> &dataSetColumn);
        ~DataInfo();

        int getVarNo();
        int getType();
        int getCutSize();
        bool nomContains(int x,int index);
        int getRange(int i){ return range[i];};

    private:
        vector<int> uniqueValues(vector<int> &vectorIn);
        vector<set<int>> createSets(vector<int> vectorIn);
        vector<int> createNomRange(int i);
};

#endif // DATAINFO_H
