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
    bool*** table_X;

    int range[10] = {1,2,3,4,5,6,7,8,9,10};

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
    bool*** get_X_Table(){ return table_X; };

    void print_X();
    void print_Action();
    void print_Y();
    void print_All();

    void threeDepthPrint();
//    vector<Result *> threeDepth();

private:
    void table_X_gen(vector<vector<int>> x);
    void loadX(vector<vector<int>> x);
    void loadAction(vector<vector<int>> a);
    void loadY(vector<vector<double>> y);
    void cleanAll();

};

#endif // ITR_H
