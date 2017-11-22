#include <iostream>

#include "Patient.cpp"
#include "VariableInfo.cpp"
#include "DataGeneration.cpp"
#include "OrdinalFilter.cpp"
#include "NominalFilter.cpp"
#include "ActionFilter.cpp"
#include "AllFilter.cpp"

using namespace std;

template<class T>
vector<T> quickDelete( int index, vector<T> vec ) // fast method that does not retain the original order of the elements
{
  vec[index] = vec.back();
  vec.pop_back();
  return vec;
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
    vector<int> id = data.getID();
    vector<Patient> patients = creatPatients(data.getDataSet(),data.getActions(),data.getY(),data.getVarType(),id);
//    printPatients(patients);

    /// Check contains difference
    /// Direct remove by ID

    /// Create variable information objects
    vector<VariableInfo> varInfo = creatVariableInfo(data.getDataSet(),data.getVarType());


    /// Filtering
    Filter *iOrdinal0;   OrdinalFilter cOrdinal0({0,5,-1}); iOrdinal0 = &cOrdinal0; /// var0, <5
    Filter *iOrdinal1;   OrdinalFilter cOrdinal1({3,2,1}); iOrdinal1 = &cOrdinal1;  /// var3, >=2
    Filter *iNominal0;   NominalFilter cNominal0(varInfo.at(6).getComb({6,10})); iNominal0 = &cNominal0;    /// var 6, combination 10, {0}
    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iActionT0;  ActionFilter cActionT0({0});    iActionT0 = &cActionT0;

    Filter *iAllFilter1;  AllFilter cAllFilter1;  iAllFilter1 = &cAllFilter1;
    cAllFilter1.addFilter(cOrdinal0);    cAllFilter1.addFilter(cOrdinal1);  cAllFilter1.addFilter(cNominal0);


    /// Filter Result print
    vector<Patient> f1 = cAllFilter1.meetCriteria(patients);
    vector<Patient> t1 = cActionT1.meetCriteria(cAllFilter1.meetCriteria(patients));

//    cout<<"Test 3:"<<endl;
//    cout<<"Variable(Cont) 0, cut by 5, result for < 5:"<<endl;
//    cout<<"Variable(Ordinal) 3, cut by 2, result for >= 3:"<<endl;
//    cout<<"Variable(Nominal) 6, check by combination no 10, {1,3}:"<<endl;
//    cout<<"Action 1:"<<endl;
//    printPatients(t1);
    printNum(cActionT1.getSum());

    vector<int> t1Index;
    double sumT1 = 0.0;
    for(auto p: t1){
        t1Index.push_back(p.getID());
    }

    /// Remove elements by index
    for(auto x:t1Index){
        patients[x] = patients.back();
        patients.pop_back();
    }

//    printPatients(cActionT0.meetCriteria(patients));
    cActionT0.meetCriteria(patients);
    printNum(cActionT0.getSum());


    return 0;
}




/*****************************************************************************************************************************************************/
