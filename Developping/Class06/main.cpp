#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
//#include "NominalFilter.cpp"
#include "ActionFilter.cpp"
#include "AllFilter.cpp"





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
    data.creatSamples(3000);
    data.preprocessing();
    double totalT0 = data.getSum();
//    data.printInfo(6);

    /// Create patient objects
    vector<int> id = data.getID();
    vector<Patient *> patients = createPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),id);
//    printPatientsXA(patients);

    /// Create variable information objects
    vector<VariableInfo> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
//    varInfo.at(1).printVarInfo();

    /// One Depth
    vector<int> variType = data.getVarType();
    int sampleSize = data.getSampleSize();


    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;

    for(unsigned int i=0; i<6; ++i){
        VariableInfo  variInfo = varInfo[i];
        pair<pair<vector<int>,vector<int>>, double> pairOut;
        vector<int> bIndex;
        vector<int> bRange;
        double bValue = 0.0;

        for(auto xi : variInfo.getCombs()){
            vector<int> iIndex = xi.first;
            vector<Patient *> copyPatients(patients);

            cAllFilter.clearAllFilter();
//            Filter *iNominal1;   NominalFilter  cNominal1(variInfo.getComb(iIndex)); iNominal1 = &cNominal1;
            Filter *iOrdinal1;   OrdinalFilter cOrdinal1(iIndex); iOrdinal1 = &cOrdinal1;

            if(iIndex.size()==2){
//                cAllFilter.addFilter(cNominal1);
            }else{
                cAllFilter.addFilter(cOrdinal1);
            }

            cActionT1.meetCriteria(cAllFilter.meetCriteria(copyPatients));
            double currentExp = (cActionT1.getSumT1()+(totalT0-cActionT1.getSumT0()))*2/sampleSize;
            if(currentExp > bValue){
                bValue = currentExp;
                bIndex = iIndex;
                bRange = xi.second;
            }

            cActionT1.resetSum();
        }
        cout<<bValue<<'\t';print1DVector(bIndex);cout<<" \t";print1DVector(bRange);cout<<"\n";
        pairOut = make_pair(make_pair(bIndex, bRange),bValue);
    }


}




/*****************************************************************************************************************************************************/
