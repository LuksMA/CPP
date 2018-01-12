#include <iostream>
#include <omp.h>

#include "DataGeneration.h"
#include "ITR.h"


using namespace std;

template<class T>
void print1DVector(vector<T> const &vectIn);

int main()
{
    /// Test data generation class
//    vector<int> varType(35,0); /// 0 for cont, 1 for ordinal, 2 for nominal
//    vector<double> rangesCont = {10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0,0.0,100.0,10.0,200.0,50.0,300.0};
//    vector<int> rangesOrd = {};
//    vector<int> rangesNom = {};
//    vector<double> rangesY = {0.0,100.0};
//    vector<int> rangesAction = {0,1};

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
    data.creatSamples(3000);
    data.preprocessing();
//    data.printDataSet();
//    data.printAction();
//    print1DVector(data.getVarType());
//    cout<<'\n'<<data.getVarType().size();


    ITR ITR_CS(data);
//    ITR_CS.print_Type();
//    cout<<endl;
//    cout<<"Sample size: "<<ITR_CS.getSampleSize()<<endl;
//    cout<<"Variable size: "<<ITR_CS.getVarSize()<<endl;
//    cout<<"Action size: "<<ITR_CS.getActionSize()<<endl;
//    cout<<"Y size: "<<ITR_CS.getYSize()<<endl;
//    ITR_CS.print_All();
//    ITR_CS.print_Range();cout<<endl;
//    ITR_CS.print_CutTable();
//    ITR_CS.print_VarInfo();


//    ITR_CS.threeDepthPrint();
    ITR_CS.threeDepth();

//   int myints[] = {50,40,30,20,10};
//   std::set<int> myset (myints,myints+10);
//   std::cout << "myset contains:";
//   for (std::set<int>::iterator it = myset.begin(); it!=myset.end(); ++it)
//      std::cout << ' ' << *it;
//
//   std::cout << '\n';

}



template<class T>
void print1DVector(vector<T> const &vectIn)
{
    cout<<"[ ";
    for(const auto &row : vectIn)
    {
        cout<<row<<' ';
    }
    cout<<']';
}

