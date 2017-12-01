#include <iostream>

#include "DataGeneration.h"
#include "Patient.h"
#include "PatientData.h"
#include "VariableInfo.h"
#include "OrdinalFilter.h"
#include "NominalFilter.h"
#include "ActionFilter.h"
#include "AllFilter.h"


vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType);
template<class T> void print1DVector(vector<T> const &vectIn);
using namespace std;







void ThreeDepthPrint(DataGeneration data, vector<VariableInfo *> varInfo, vector<Patient *> patients)
{
    int num = 0;
    pair<pair<vector<vector<int>>,vector<vector<int>>>, double> pairOut;

    vector<int> bIndexI, bIndexJ, bIndexK;
    vector<int> bRangeI, bRangeJ, bRangeK;
    double bValue = 0.0;

    Filter *iActionT1;
    ActionFilter cActionT1({1});
    iActionT1 = &cActionT1;
    Filter *iAllFilter;
    AllFilter cAllFilter;
    iAllFilter = &cAllFilter;

//    for(int i=0; i<varInfo.size(); ++i){  // loop1
    for(int i=0; i<5; ++i)   // loop1
    {
        VariableInfo  *variInfoI = varInfo[i];

//        for(int j=i+1; j<varInfo.size(); ++j){   // loop2
        for(int j=i+1; j<5; ++j)    // loop2
        {
            VariableInfo  *variInfoJ = varInfo[j];

//            for(int k=j+1; k<varInfo.size(); ++k){   // loop3
            for(int k=j+1; k<5; ++k)    // loop3
            {
                VariableInfo  *variInfoK = varInfo[k];

                vector<int> bIndexIVar, bIndexJVar, bIndexKVar;
                vector<int> bRangeIVar, bRangeJVar, bRangeKVar;
                double bValueVar = 0.0;

                for(auto xi : variInfoI->getCombs())    // loop4
                {
                    for(auto xj : variInfoJ->getCombs())    // loop5
                    {
                        for(auto xk : variInfoK->getCombs())    // loop6
                        {
                            cAllFilter.clearAllFilter();

                            if(variInfoI->getVarType()==2)
                            {
                                cAllFilter.addFilter(*new NominalFilter(xi.second,xi.first[0]));
                            }
                            else
                            {
                                cAllFilter.addFilter(*new OrdinalFilter(xi.first[1],xi.first[0],xi.first[2]));
                            }
                            if(variInfoJ->getVarType()==2)
                            {
                                cAllFilter.addFilter(*new NominalFilter(xj.second,xj.first[0]));
                            }
                            else
                            {
                                cAllFilter.addFilter(*new OrdinalFilter(xj.first[1],xj.first[0],xj.first[2]));
                            }
                            if(variInfoK->getVarType()==2)
                            {
                                cAllFilter.addFilter(*new NominalFilter(xk.second,xk.first[0]));
                            }
                            else
                            {
                                cAllFilter.addFilter(*new OrdinalFilter(xk.first[1],xk.first[0],xk.first[2]));
                            }

                            cActionT1.meetCriteria(cAllFilter.meetCriteria(patients));
                            double currentExp = (cActionT1.getSumT1()+(data.getSumT0()-cActionT1.getSumT0()))*2/data.getSampleSize();
                            if(currentExp > bValueVar)
                            {
                                bValueVar = currentExp;
                                bRangeIVar = xi.second;
                                bRangeJVar = xj.second;
                                bRangeKVar = xk.second;
                                bIndexIVar = xi.first;
                                bIndexJVar = xj.first;
                                bIndexKVar = xk.first;
                            }
                            if(currentExp > bValue)
                            {
                                bValue = currentExp;
                                vector<vector<int>> indices = {xi.first,xj.first,xk.first};
                                vector<vector<int>> ranges = {xi.second,xj.second,xk.second};
                                pairOut = make_pair(make_pair(indices, ranges),bValue);
                            }
                            cActionT1.resetSum();
                        }  // loop6
                    }  // loop5
                }  // loop4
                cout<<num++<<": "<<bValueVar<<'\t';
                print1DVector(bIndexIVar);
                print1DVector(bIndexJVar);
                print1DVector(bIndexKVar);
//                cout<<" \t";print1DVector(bRangeIVar);print1DVector(bRangeJVar);
                cout<<"\n";
            }  // loop3
        }  // loop2
    }  // loop1
    cout<<"Best:\n"<<pairOut.second;
    cout<<"\tIndex: ";
    print1DVector(pairOut.first.first[0]);
    print1DVector(pairOut.first.first[1]);
    print1DVector(pairOut.first.first[2]);
    cout<<"\nRange: ";
    print1DVector(pairOut.first.second[0]);
    print1DVector(pairOut.first.second[1]);
    print1DVector(pairOut.first.second[2]);
    cout<<endl;
}


int main()
{
    /// Test data generation class
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,4,0,4,0,4};
    vector<int> rangesNom = {0,4,0,4,0,4};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(300);
    data.preprocessing();
//    data.printInfo(6);

    /// Create patient objects
    PatientData pData(data);
    vector<Patient *> patients = pData.getPatients();
//    pData.printPatients(patients);

    /// Create variable information objects
    vector<VariableInfo *> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
//    varInfo.at(6)->printVarInfo();


    /// Three Depth
//    ThreeDepthPrint(data, varInfo, patients);

//    vector<int> v1111;
    for(int i=0; i<5; ++i)   // loop1
    {
        VariableInfo  *variInfoI = varInfo[i];

//        for(int j=i+1; j<varInfo.size(); ++j){   // loop2
        for(int j=i+1; j<5; ++j)    // loop2
        {
            VariableInfo  *variInfoJ = varInfo[j];

//            for(int k=j+1; k<varInfo.size(); ++k){   // loop3
            for(int k=j+1; k<5; ++k)    // loop3
            {
                VariableInfo  *variInfoK = varInfo[k];
                double best = 0.0;
                for(auto xi : variInfoI->getCuts())            // loop4
                {
                    for(auto xj : variInfoJ->getCuts())    // loop5
                    {
                        for(auto xk : variInfoK->getCuts())    // loop6
                        {
                            double v0000 = 0.0;
                            double v0001 = 0.0;
                            double v0010 = 0.0;
                            double v0011 = 0.0;
                            double v0100 = 0.0;
                            double v0101 = 0.0;
                            double v0110 = 0.0;
                            double v0111 = 0.0;
                            double v1000 = 0.0;
                            double v1001 = 0.0;
                            double v1010 = 0.0;
                            double v1011 = 0.0;
                            double v1100 = 0.0;
                            double v1101 = 0.0;
                            double v1110 = 0.0;
                            double v1111 = 0.0;

                            for(auto p : patients)
                            {
                                if(p->getX(i)<xi)
                                {
                                    if(p->getX(j)<xj)
                                    {
                                        if(p->getX(k)<xk)
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v0000 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0001 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v0010 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0011 += p->getY()[0];
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(p->getX(k)<xk)
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v0100 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0101 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v0110 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v0111 += p->getY()[0];
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if(p->getX(j)<xj)
                                    {
                                        if(p->getX(k)<xk)
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1000 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1001 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1010 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1011 += p->getY()[0];
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(p->getX(k)<xk)
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1100 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1101 += p->getY()[0];
                                            }
                                        }
                                        else
                                        {
                                            if(p->getAction()[0]==1)
                                            {
                                                v1110 += p->getY()[0];
                                            }
                                            else
                                            {
                                                v1111 += p->getY()[0];
                                            }
                                        }
                                    }
                                }
                            }
//    cout<<"0000: "<<v0000<<endl;
//    cout<<"0001: "<<v0001<<endl;
//    cout<<"0001: "<<v0101<<endl;

                            double T0 = 732.557;
                            double sum1 = v0001 + (T0 - v0000);
                            double sum2 = v0011 + (T0 - v0010);
                            double sum3 = v0101 + (T0 - v0100);
                            double sum4 = v0111 + (T0 - v0110);
                            double sum5 = v1001 + (T0 - v1000);
                            double sum6 = v1011 + (T0 - v1010);
                            double sum7 = v1101 + (T0 - v1100);
                            double sum8 = v1111 + (T0 - v1110);
//    cout<<"sum1: "<<sum1<<endl;
                            double sum[] = {sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8};
//                            cout<<*max_element(sum,sum+8)<<endl;
                            double temp = *max_element(sum,sum+8);
                            if(temp>best){
                                best = temp;
                            }
                        }
                    }

                }
                cout<<best/3<<endl;
            }
        }
    }





//    double v0000 = 0.0;
//    double v0001 = 0.0;
//    double v0010 = 0.0;
//    double v0011 = 0.0;
//    double v0100 = 0.0;
//    double v0101 = 0.0;
//    double v0110 = 0.0;
//    double v0111 = 0.0;
//    double v1000 = 0.0;
//    double v1001 = 0.0;
//    double v1010 = 0.0;
//    double v1011 = 0.0;
//    double v1100 = 0.0;
//    double v1101 = 0.0;
//    double v1110 = 0.0;
//    double v1111 = 0.0;
//
//    for(auto p : patients)
//    {
//        if(p->getX(0)<5)
//        {
//            if(p->getX(1)<5)
//            {
//                if(p->getX(2)<5)
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v0000 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v0001 += p->getY()[0];
//                    }
//                }
//                else
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v0010 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v0011 += p->getY()[0];
//                    }
//                }
//            }
//            else
//            {
//                if(p->getX(2)<5)
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v0100 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v0101 += p->getY()[0];
//                    }
//                }
//                else
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v0110 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v0111 += p->getY()[0];
//                    }
//                }
//            }
//        }
//        else
//        {
//            if(p->getX(1)<5)
//            {
//                if(p->getX(2)<5)
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v1000 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v1001 += p->getY()[0];
//                    }
//                }
//                else
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v1010 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v1011 += p->getY()[0];
//                    }
//                }
//            }
//            else
//            {
//                if(p->getX(2)<5)
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v1100 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v1101 += p->getY()[0];
//                    }
//                }
//                else
//                {
//                    if(p->getAction()[0]==1)
//                    {
//                        v1110 += p->getY()[0];
//                    }
//                    else
//                    {
//                        v1111 += p->getY()[0];
//                    }
//                }
//            }
//        }
//    }
////    cout<<"0000: "<<v0000<<endl;
////    cout<<"0001: "<<v0001<<endl;
////    cout<<"0001: "<<v0101<<endl;
//
//    double T0 = 732.557;
//    double sum1 = v0001 + (T0 - v0000);
//    double sum2 = v0011 + (T0 - v0010);
//    double sum3 = v0101 + (T0 - v0100);
//    double sum4 = v0111 + (T0 - v0110);
//    double sum5 = v1001 + (T0 - v1000);
//    double sum6 = v1011 + (T0 - v1010);
//    double sum7 = v1101 + (T0 - v1100);
//    double sum8 = v1111 + (T0 - v1110);
////    cout<<"sum1: "<<sum1<<endl;
//    double sum[] = {sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8};
//    cout<<*max_element(sum,sum+8);





}




/*****************************************************************************************************************************************************/
vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType)
{
    vector<VariableInfo *> variables;
    for(int i=0; i<varType.size(); ++i)
    {
        variables.push_back(new VariableInfo(i,varType.at(i),dataSet.at(i)));
    }
    return variables;
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
