#include <iostream>
#include <omp.h>

#include "DataGeneration.h"
#include "ITR.h"


using namespace std;

int main()
{
    /// Test data generation class
    vector<int> varType(35,0); /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {};
    vector<int> rangesNom = {};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(3000);
    data.preprocessing();
//    data.printDataSet();
//    data.printAction();


    ITR ITR_CS(data);
//    ITR_CS.threeDepthPrint();

    ITR_CS.threeDepth();







}
