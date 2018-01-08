#ifndef ITR_H
#define ITR_H

#include "DataGeneration.h"
#include "Dyn2array.h"
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
    void clean_X();
    void clean_Action();
    void clean_Y();
    void cleanAll();

private:
    void loadX(vector<vector<int>> x);
    void loadAction(vector<vector<int>> a);
    void loadY(vector<vector<double>> y);

};

#endif // ITR_H
