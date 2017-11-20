#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
#include "NominalFilter.cpp"
#include "ActionFilter.cpp"
#include "AllFilter.cpp"

using namespace std;


pair<pair<vector<int>,vector<int>>, double> OneDepthOrdinal(VariableInfo variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize);
pair<pair<vector<int>,vector<int>>, double> OneDepthNominal(VariableInfo variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize);
pair<pair<vector<int>,vector<int>>, double> OneDepth(vector<VariableInfo> varInfo, pair<vector<Patient>,vector<Patient>> patients, DataGeneration data);
pair<pair<vector<vector<int>>,vector<vector<int>>>, double> TwoDepth(vector<VariableInfo> varInfo, pair<vector<Patient>,vector<Patient>> patients, DataGeneration data){
    pair<pair<vector<vector<int>>,vector<vector<int>>>, double> pairOut;
    vector<int> bIndexI;
    vector<int> bIndexJ;
    vector<int> bRangeI;
    vector<int> bRangeJ;

    double bValue = 0;
    vector<int> varType = data.getVarType();
    int sampleSize = data.getSampleSize();

    Filter *iAction;  ActionFilter cAction({1});    iAction=&cAction;

    for(int i=0; i<data.getCovariateSize(); ++i){
        for(int j=i+1; j<data.getCovariateSize(); ++j){
            cout<<"i:"<<i<<' '<<varType.at(i)<<' '<<"j:"<<j<<' '<<varType.at(j)<<endl;
            VariableInfo  infoI = varInfo.at(i);
            VariableInfo  infoJ = varInfo.at(j);

            for(auto xi : infoI.getCombs()){
                vector<int> firstI = xi.first;
                Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;
                if(varType.at(i)==2){
                    Filter *iNominal1;   NominalFilter  cNominal1(varInfo.at(i).getComb(firstI)); iNominal1 = &cNominal1;
                    cAllFilter.addFilter(cNominal1);
                }else{
                    Filter *iOrdinal1;   OrdinalFilter cOrdinal1(firstI); iOrdinal1 = &cOrdinal1;
                    cAllFilter.addFilter(cOrdinal1);
                    cAllFilter.addFilter(cAction);
                    double temp = expect(cAllFilter.meetCriteria(patients).first,sampleSize)+expect(cAllFilter.meetCriteria(patients).second,sampleSize);
                    if(temp > bValue){
                        bValue = temp;
                        bIndexI = firstI;
                        bRangeI = xi.second;
                    }
                }
//                for(auto xj :infoJ.getCombs()){
//                    vector<int> firstJ = xj.first;
//                    if(varType.at(j)==2){
//                        Filter *iNominal2;   NominalFilter  cNominal2(varInfo.at(j).getComb(firstJ)); iNominal2 = &cNominal2;
//                        cAllFilter.addFilter(cNominal2);
//                    }else{
//                        Filter *iOrdinal2;   OrdinalFilter cOrdinal2(firstJ); iOrdinal2 = &cOrdinal2;
//                        cAllFilter.addFilter(cOrdinal2);
//                    }
//                    cAllFilter.addFilter(cAction);
//                    double temp = expect(cAllFilter.meetCriteria(patients).first,sampleSize)+expect(cAllFilter.meetCriteria(patients).second,sampleSize);
//                    if(temp > bValue){
//                        bValue = temp;
//                        bRange.empty();bRange.push_back(firstI);
////                        bRange.push_back(firstJ);
//                        bIndex.empty();bIndex.push_back(xi.second);
////                        bIndex.push_back(xj.second);
//                    }
//                }
            }
        }
    }
    vector<vector<int>> indices; indices.push_back(bIndexI);
    vector<vector<int>> ranges; ranges.push_back(bRangeI);

    pairOut = make_pair(make_pair(indices, ranges),bValue);
    return pairOut;

}


int main(){
    /// Test data generation class
    vector<int> varType= {0,0,0,1,1,1,2,2,2}; /// 0 for cont, 1 for ordinal, 2 for nominal
    vector<double> rangesCont = {0.0,100.0,10.0,200.0,50.0,300.0};
    vector<int> rangesOrd = {0,4,0,4,0,4};
    vector<int> rangesNom = {0,4,0,4,0,4};
    vector<double> rangesY = {0.0,100.0};
    vector<int> rangesAction = {0,1};

    DataGeneration data(varType,rangesY,rangesAction,rangesCont,rangesOrd,rangesNom);
    data.creatSamples(20);
    data.preprocessing();
//    data.printInfo(6);

    /// Create patient objects
    vector<Patient> patientsAll = creatPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),data.getID());
    vector<Patient> patientsEmpty;
    patientsEmpty.empty();
    pair<vector<Patient> , vector<Patient>> patients = make_pair(patientsAll,patientsEmpty);
//    printPatients(patients.first);

    /// Create variable information objects
    vector<VariableInfo> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());
//    varInfo.at(0).printVarInfo();


    /// Filtering 2 Depth
    /// Filter Result print
    pair<pair<vector<vector<int>>,vector<vector<int>>>, double> ResultAll2 = TwoDepth(varInfo, patients, data);
    cout<<ResultAll2.second<<'\t';
    cout<<"Index: ";print1DVector(ResultAll2.first.first.at(0));
    cout<<"\tRange: ";print1DVector(ResultAll2.first.second.at(0));
    printPair2(ResultAll2.first);




return 0;
}


/*****************************************************************************************************************************************************/
pair<pair<vector<int>,vector<int>>, double> OneDepthOrdinal(VariableInfo variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    vector<int> bIndex;
    vector<int> bRange;
    double bValue = 0;

    Filter *iAction1;  ActionFilter cAction1({1});    iAction1=&cAction1;

    for(auto x : variInfo.getCombs()){
        vector<int> First = x.first;
        vector<int> Second = x.second;

        Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
        Filter *iOrdinal1;   OrdinalFilter cOrdinal1(First); iOrdinal1 = &cOrdinal1;
        cAllFilter1.addFilter(cOrdinal1);
        cAllFilter1.addFilter(cAction1);

        double temp = expect(cAllFilter1.meetCriteria(patients).first,sampleSize)+expect(cAllFilter1.meetCriteria(patients).second,sampleSize);

        if(temp > bValue){
            bValue = temp;
            bRange = Second;
            bIndex = First;
        }
    }
    pairOut = make_pair(make_pair(bIndex, bRange),bValue);

    return pairOut;

}

pair<pair<vector<int>,vector<int>>, double> OneDepthNominal(VariableInfo variInfo, pair<vector<Patient>,vector<Patient>> patients, int sampleSize){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    vector<int> bIndex;
    vector<int> bRange;
    double bValue = 0;

    Filter *iAction1;  ActionFilter cAction1({1});    iAction1=&cAction1;

    for(auto x : variInfo.getCombs()){
        vector<int> First = x.first;
        vector<int> Second = x.second;

        Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
        Filter *iNominal1;   NominalFilter  cNominal1(variInfo.getComb(First)); iNominal1 = &cNominal1;
        cAllFilter1.addFilter(cNominal1);
        cAllFilter1.addFilter(cAction1);

        double temp = expect(cAllFilter1.meetCriteria(patients).first,sampleSize)+expect(cAllFilter1.meetCriteria(patients).second,sampleSize);

        if(temp > bValue){
            bValue = temp;
            bRange = Second;
            bIndex = First;
        }
    }
    pairOut = make_pair(make_pair(bIndex, bRange), bValue);

    return pairOut;
}

pair<pair<vector<int>,vector<int>>, double> OneDepth(vector<VariableInfo> varInfo, pair<vector<Patient>,vector<Patient>> patients, DataGeneration data){
    pair<pair<vector<int> , vector<int>>, double> pairOut;
    double bValue = 0;
    int sampleSize = data.getSampleSize();
    vector<int> variType = data.getVarType();
    for(int i=0; i<data.getCovariateSize(); ++i){
        if(variType.at(i)==2){
            pair<pair<vector<int>,vector<int>>, double> tempPair = OneDepthNominal(varInfo.at(i),patients,sampleSize);
            if(tempPair.second>bValue){
                bValue = tempPair.second;
                pairOut = tempPair;
            }
        }else{
            pair<pair<vector<int>,vector<int>>, double> tempPair = OneDepthOrdinal(varInfo.at(i),patients,sampleSize);
            if(tempPair.second > bValue){
                bValue = tempPair.second;
                pairOut = tempPair;
            }
        }
    }
    return pairOut;
}
