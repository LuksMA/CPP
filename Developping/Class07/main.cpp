#include <iostream>

#include "DataGeneration.h"
#include "Patient.h"
#include "PatientData.h"
#include "VariableInfo.h"
#include "OrdinalFilter.h"
#include "NominalFilter.h"
#include "ActionFilter.h"
#include "AllFilter.h"
//#include "Depths.cpp"

vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType);
void ThreeDepthPrint(DataGeneration &data, vector<VariableInfo> varInfo, vector<Patient *> patients);
using namespace std;

int main(){
    /// Test data generation class
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,4,0,4,0,4};
    vector<int> rangesNom = {0,4,0,4,0,4};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(30);
    data.preprocessing();
    cout<<"T0: "<<data.getSumT0()<<endl;
    cout<<"T1: "<<data.getSumT1()<<endl;
//    data.printInfo(6);

    /// Create patient objects
    PatientData pData(data);
    vector<Patient *> patients = pData.getPatients();
    pData.printPatients(patients);

    /// Create variable information objects
    vector<VariableInfo *> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
    varInfo.at(6)->printVarInfo();

    /// One Depth
//    OneDepthPrint(data, varInfo, patients);

    /// Two Depth
//    TwoDepthPrint(data, varInfo, patients);

    /// Three Depth
//    ThreeDepthPrint(data, varInfo, patients);
}




/*****************************************************************************************************************************************************/
vector<VariableInfo *> creatVariableInfo(vector<vector<int>> dataSet,vector<int> varType){
    vector<VariableInfo *> variables;
    for(int i=0;i<varType.size();++i){
        variables.push_back(new VariableInfo(i,varType.at(i),dataSet.at(i)));
    }
    return variables;
}


void ThreeDepthPrint(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients){
    int num = 0;
    pair<pair<vector<vector<int>>,vector<vector<int>>>, double> pairOut;

    vector<int> bIndexI, bIndexJ, bIndexK;
    vector<int> bRangeI, bRangeJ, bRangeK;
    double bValue = 0.0;

    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;

//    for(unsigned  i=0; i<5; ++i){  // loop1
//        VariableInfo  variInfoI = varInfo.at(i);
//
//        for(unsigned  j=i+1; j<5; ++j){   // loop2
//            VariableInfo  variInfoJ = varInfo.at(j);
//
//            for(unsigned  k=j+1; k<5; ++k){   // loop3
//                VariableInfo  variInfoK = varInfo.at(k);
//
//                vector<int> bIndexIVar, bIndexJVar, bIndexKVar;
//                vector<int> bRangeIVar, bRangeJVar, bRangeKVar;
//                double bValueVar = 0.0;
//
//                for(auto& xi : variInfoI.getCuts()){   // loop4
////                    vector<int> firstI = xi.first;
////                    vector<int> secondI = xi.second;
//
//                    for(auto& xj : variInfoJ.getCuts()){   // loop5
////                        vector<int> firstJ = xj.first;
////                        vector<int> secondJ = xj.second;
//
//                        for(auto& xk : variInfoK.getCuts()){   // loop6
////                            vector<int> firstK = xk.first;
////                            vector<int> secondK = xk.second;
//
//                            cAllFilter.clearAllFilter();
//
////                            if(firstI.size()==2){
//////                                cAllFilter.addFilter(*new NominalFilter(secondI,firstI[0]));
////                            }else{
//                                cAllFilter.addFilter(*new OrdinalFilter(xi.first,xi.second));
////                            }
////                            if(firstJ.size()==2){
////                                cAllFilter.addFilter(*new NominalFilter(secondJ,firstJ[0]));
////                            }else{
//                                cAllFilter.addFilter(*new OrdinalFilter(xj.first,xj.second));
////                            }
////                            if(firstK.size()==2){
////                                cAllFilter.addFilter(*new NominalFilter(secondK,firstK[0]));
////                            }else{
//                                cAllFilter.addFilter(*new OrdinalFilter(xk.first,xk.second));
////                            }
//
//                            cActionT1.meetCriteria(cAllFilter.meetCriteria(patients));
//
//                            double currentExp1 = (cActionT1.getSumT1()+(data.getSumT0()-cActionT1.getSumT0()))*2/data.getSampleSize();
//                            double currentExp2 = ((data.getSumT1()-cActionT1.getSumT1())+cActionT1.getSumT0())*2/data.getSampleSize();
//                            double currentExp ;
//                            if(currentExp1 > currentExp2){
//                                currentExp = currentExp1;
//                            }else{
//                                currentExp = currentExp2;
//                            }
//                            if(currentExp > bValueVar){
//                                bValueVar = currentExp;
////                                bRangeIVar = secondI;   bRangeJVar = secondJ;   bRangeKVar = secondK;
////                                bIndexIVar = firstI;    bIndexJVar = firstJ;    bIndexKVar = firstK;
//                            }
//                            if(currentExp > bValue){
//                                bValue = currentExp;
////                                vector<vector<int>> indices = {firstI,firstJ,firstK};
////                                vector<vector<int>> ranges = {secondI,secondJ,secondK};
////                                pairOut = make_pair(make_pair(indices, ranges),bValue);
//                            }
//                            cActionT1.resetSum();
//                        }  // loop6
//                    }  // loop5
//                }  // loop4
//                cout<<num++<<": "<<bValueVar<<'\t';
////                print1DVector(bIndexIVar);print1DVector(bIndexJVar);print1DVector(bIndexKVar);
////                cout<<" \t";print1DVector(bRangeIVar);print1DVector(bRangeJVar);
//                cout<<"\n";
//            }  // loop3
//        }  // loop2
//    }  // loop1
//    cout<<"Best:\n"<<bValue;
////    cout<<"\tIndex: ";print1DVector(pairOut.first.first[0]);print1DVector(pairOut.first.first[1]);print1DVector(pairOut.first.first[2]);
////    cout<<"\nRange: ";print1DVector(pairOut.first.second[0]);print1DVector(pairOut.first.second[1]);print1DVector(pairOut.first.second[2]);
////    cout<<endl;
}
