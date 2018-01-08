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
    data.creatSamples(5);
    data.preprocessing();
//    data.printDataSet();
//    data.printAction();


    ITR ITR_CS(data);
    cout<<"Sample size: "<<ITR_CS.getSampleSize()<<endl;
    cout<<"Variable size: "<<ITR_CS.getVarSize()<<endl;
    cout<<"Action size: "<<ITR_CS.getActionSize()<<endl;
    cout<<"Y size: "<<ITR_CS.getYSize()<<endl;

    cout<<"\nX:\n"; ITR_CS.print_X();
    cout<<"\nAction:\n"; ITR_CS.print_Action();
    cout<<"\nY:\n"; ITR_CS.print_Y();
//    ITR_CS.print_All();

    cout<<"\nTest X[0][1]: ";
    cout<<ITR_CS.get_X()[0][1]<<endl;
    cout<<"Test Action[2][0]: ";
    cout<<ITR_CS.get_Action()[2][0]<<endl;
    cout<<"Test Y[2][0]: ";
    cout<<ITR_CS.get_Y()[2][0]<<endl;


    ITR_CS.clean_X();
    ITR_CS.clean_Action();
    ITR_CS.clean_Y();
    ITR_CS.cleanAll();


}
