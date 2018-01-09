#ifndef ITR_H
#define ITR_H

#include "DataGeneration.h"
#include "Result.h"
#include <iostream>

using namespace std;

class ITR
{
private:
    int** var_X;
    int** var_A;
    double** var_Y;

    int sample_Size;   // row
    int var_Size;      // column
    int action_Size;
    int y_Size;

    double T0;

public:
    ITR(DataGeneration &data);
    ~ITR();


    int getSampleSize();
    int getVarSize();
    int getActionSize();
    int getYSize();
    int** get_X(){ return var_X;};
    int** get_Action(){ return var_A;};
    double** get_Y(){ return var_Y;};

    void print_X();
    void print_Action();
    void print_Y();
    void print_All();

    void threeDepthPrint();
    vector<Result *> threeDepth();
    int cut(int* index, int var1, int cut1, int var2, int cut2, int var3, int cut3);


private:
    void loadX(vector<vector<int>> x);
    void loadAction(vector<vector<int>> a);
    void loadY(vector<vector<double>> y);
    void cleanAll();

};

#endif // ITR_H
