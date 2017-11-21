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
    Filter *iAction;  ActionFilter cAction({1});    iAction = &cAction;

    for(int i=0; i<2; ++i){  // loop1
        VariableInfo  variInfoI = varInfo.at(i);
//        infoI.printVarInfo();
        for(int j=i+1; j<2; ++j){   // loop2
            VariableInfo  variInfoJ = varInfo.at(j);
//            infoJ.printVarInfo();
            cout<<"i:"<<i<<' '<<varType.at(i)<<' '<<"j:"<<j<<' '<<varType.at(j)<<endl;
            for(auto xi : variInfoI.getCombs()){   // loop3
                vector<int> FirstI = xi.first;
                vector<int> SecondI = xi.second;

                for(auto xj :variInfoJ.getCombs()){   // loop4
                    vector<int> FirstJ = xj.first;
                    vector<int> SecondJ = xj.second;

                    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;
                    Filter *iNominal1;   NominalFilter  cNominal1(variInfoI.getComb(FirstI)); iNominal1 = &cNominal1;
                    Filter *iOrdinal1;   OrdinalFilter cOrdinal1(FirstI); iOrdinal1 = &cOrdinal1;
                    Filter *iNominal2;   NominalFilter  cNominal2(variInfoI.getComb(FirstJ)); iNominal2 = &cNominal2;
                    Filter *iOrdinal2;   OrdinalFilter cOrdinal2(FirstJ); iOrdinal2 = &cOrdinal2;

                    if(FirstI.size()==2){
                        cAllFilter.addFilter(cNominal1);
                    }else{
                        cAllFilter.addFilter(cOrdinal1);
                    }
                    if(FirstJ.size()==2){
                        cAllFilter.addFilter(cNominal2);
                    }else{
                        cAllFilter.addFilter(cOrdinal2);
                    }
                    cAllFilter.addFilter(cAction);

                    double temp = expect(cAllFilter.meetCriteria(patients).first,sampleSize)+expect(cAllFilter.meetCriteria(patients).second,sampleSize);
                    if(temp > bValue){
                        bValue = temp;
                        bRangeI = SecondI;
                        bIndexI = FirstI;
                        bRangeJ = SecondJ;
                        bIndexJ = FirstJ;
                    }
                }
            }
        }
    }
    vector<vector<int>> indices; indices.push_back(bIndexI);indices.push_back(bIndexJ);
//    indices.push_back(bIndexJ);
    vector<vector<int>> ranges; ranges.push_back(bRangeI);ranges.push_back(bRangeJ);
//    ranges.push_back(bRangeJ);

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

    cout<<ResultAll2.second<<'\n';
    cout<<"Index 1: ";print1DVector(ResultAll2.first.first.at(0));
    cout<<"\tRange 1: ";print1DVector(ResultAll2.first.second.at(0));
    cout<<"\nIndex 2: ";print1DVector(ResultAll2.first.first.at(1));
    cout<<"\tRange 2: ";print1DVector(ResultAll2.first.second.at(1));


//    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;
//    Filter *iAction;  ActionFilter cAction({1});    iAction=&cAction;
//    Filter *iOrdinal1;   OrdinalFilter cOrdinal1({0,1,-1}); iOrdinal1 = &cOrdinal1;
//    cAllFilter.addFilter(cOrdinal1);
//    cAllFilter.addFilter(cAction);
//    double temp = expect(cAllFilter.meetCriteria(patients).first,20)+expect(cAllFilter.meetCriteria(patients).second,20);
//    cout<<temp;

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
