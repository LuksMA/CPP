#include <iostream>
#include <omp.h>

#include "DataGeneration.h"
#include "ITR.h"


using namespace std;

int main()
{
    /// Test data generation class
    vector<int> varType(25,0); /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<int> varType1(5,1);
    vector<int> varType2(5,2);
    varType.insert(varType.end(),varType1.begin(),varType1.end());
    varType.insert(varType.end(),varType2.begin(),varType2.end());

    vector<double> rangesCont = {50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,4,0,4,0,4,0,4,0,4};
    vector<int> rangesNom = {0,4,0,4,0,4,0,4,0,4};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(30);
    ITR ITR_CS(data);
//    ITR_CS.print_CutTable();

    ITR_CS.threeDepthPrint();
//    ITR_CS.threeDepth();

}



