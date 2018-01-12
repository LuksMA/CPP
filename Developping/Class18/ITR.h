#ifndef ITR_H
#define ITR_H

#include "DataGeneration.h"
#include "Result.h"
#include "DataInfo.h"
#include <iostream>

using namespace std;

class ITR
{
private:
    vector<int> var_Type; // var_Size

    int** var_X;     // X 2d matrix             (sample_Size x var_Size)
    int** var_A;     // Action 2d matrix        (sample_Size x action_Size)
    double** var_Y;  // Y 2d matrix             (sample_Size x y_Size)
    bool*** table_X; // lookup table 3d matrix  (var_Size x cut_Size[i] x sample_Size)
    DataInfo* info;  // Variable info vector    (var_Size)
    int* cut_Size;   // Cut size vector         (var_Size)

    int sample_Size;
    int var_Size;
    int action_Size;
    int y_Size;

    double T0;       // Total sum of Non Treatment

public:
    ITR(DataGeneration &data);
    ~ITR();

    int getSampleSize();
    int getVarSize();
    int getActionSize();
    int getYSize();
    int* get_CutSize(){ return cut_Size;};
    int** get_X(){ return var_X;};
    int** get_Action(){ return var_A;};
    double** get_Y(){ return var_Y;};
    bool*** get_X_Table(){ return table_X; };

    void print_X();
    void print_Action();
    void print_Y();
    void print_All();
    void print_Range();
    void print_Type();
    void print_CutTable();
    void print_VarInfo(int i);
    void print_VarInfo();

    void threeDepthPrint();
    vector<Result *> threeDepth();

private:
    void init();
    void load_CutSize();
    void load_table_X(vector<vector<int>> x);
    void load_X(vector<vector<int>> x);
    void load_Action(vector<vector<int>> a);
    void load_Y(vector<vector<double>> y);
    void cleanAll();

};

#endif // ITR_H
