#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
#include "NominalFilter.cpp"
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
//    data.printInfo(6);

    /// Create patient objects
    vector<int> id = data.getID();
    vector<Patient> patients = creatPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),id);
//    printPatients(patients);

    /// Create variable information objects
    vector<VariableInfo> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
//    varInfo.at(1).printVarInfo();

    /// One Depth


    vector<int> variType = data.getVarType();
    int sampleSize = data.getSampleSize();

    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iActionT0;  ActionFilter cActionT0({0});    iActionT0 = &cActionT0;

    for(int i=0; i<6; ++i){
        VariableInfo  variInfo = varInfo.at(i);
        pair<pair<vector<int>,vector<int>>, double> pairOut;
        vector<int> bIndex;
        vector<int> bRange;
        double bValue = 0.0;

        for(auto xi : variInfo.getCombs()){
            vector<int> iIndex = xi.first;
            vector<Patient> copyPatients(patients);

            Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter; cAllFilter.clearAllFilter();
            Filter *iNominal1;   NominalFilter  cNominal1(variInfo.getComb(iIndex)); iNominal1 = &cNominal1;
            Filter *iOrdinal1;   OrdinalFilter cOrdinal1(iIndex); iOrdinal1 = &cOrdinal1;
            if(iIndex.size()==2){
                cAllFilter.addFilter(cNominal1);
            }else{
                cAllFilter.addFilter(cOrdinal1);
            }

            vector<Patient> f1 = cAllFilter.meetCriteria(copyPatients);


            vector<int> f1Index;
            for(auto p: f1){
                f1Index.push_back(p.getID());
            }

            reverse(f1Index.begin(),f1Index.end());
            for(auto x:f1Index){
                copyPatients[x] = copyPatients.back();
                copyPatients.pop_back();
            }
            cActionT1.meetCriteria(f1);
            cActionT0.meetCriteria(copyPatients);

            double currentExp = (cActionT1.getSum()+cActionT0.getSum())*2/sampleSize;
            if(currentExp > bValue){
                bValue = currentExp;
                bIndex = iIndex;
                bRange = xi.second;
            }

            cActionT1.resetSum();
            cActionT0.resetSum();
        }
        cout<<bValue<<'\t';print1DVector(bIndex);cout<<" \t";print1DVector(bRange);cout<<"\n";

        pairOut = make_pair(make_pair(bIndex, bRange),bValue);
    }

}




/*****************************************************************************************************************************************************/
