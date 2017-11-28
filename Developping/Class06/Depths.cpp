pair<pair<vector<int>,vector<int>>, double> OneDepth(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients);
void OneDepthPrint(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients){
    vector<int> variType = data.getVarType();
    int sampleSize = data.getSampleSize();
    double totalT0 = data.getSum();

    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;

    vector<int> bIndex;
    vector<int> bRange;
    double bValue = 0.0;

    pair<pair<vector<int>,vector<int>>, double> pairOut;
    for(unsigned int i=0; i<variType.size(); ++i){   /// Loop 1
        VariableInfo  variInfo = varInfo[i];

        vector<int> bIndexVar;
        vector<int> bRangeVar;
        double bValueVar = 0.0;

        for(auto xi : variInfo.getCombs()){         /// Loop 2
            vector<int> iIndex = xi.first;
            vector<Patient *> copyPatients(patients);

            cAllFilter.clearAllFilter();
            Filter *iNominal1;   NominalFilter  cNominal1(variInfo.getComb(iIndex)); iNominal1 = &cNominal1;
            Filter *iOrdinal1;   OrdinalFilter cOrdinal1(iIndex); iOrdinal1 = &cOrdinal1;

            if(iIndex.size()==2){
                cAllFilter.addFilter(cNominal1);
            }else{
                cAllFilter.addFilter(cOrdinal1);
            }

            cActionT1.meetCriteria(cAllFilter.meetCriteria(copyPatients));
            double currentExp = (cActionT1.getSumT1()+(totalT0-cActionT1.getSumT0()))*2/sampleSize;
            if(currentExp > bValue){
                bValue = currentExp;    bValueVar = currentExp;
                bIndex = iIndex;        bIndexVar = iIndex;
                bRange = xi.second;     bRangeVar = xi.second;
            }
            if(currentExp > bValueVar){
                bValueVar = currentExp;
                bIndexVar = iIndex;
                bRangeVar = xi.second;
            }
            cActionT1.resetSum();
        }
        cout<<bValueVar<<'\t';print1DVector(bIndexVar);cout<<" \t";print1DVector(bRangeVar);cout<<"\n";
    }
    pairOut = make_pair(make_pair(bIndex, bRange),bValue);

    cout<<"Best:\n"<<pairOut.second;
    cout<<"\tIndex: ";print1DVector(pairOut.first.first);
    cout<<"\tRange: ";print1DVector(pairOut.first.second);
    cout<<endl;
}






pair<pair<vector<int>,vector<int>>, double> OneDepth(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients){
    vector<int> variType = data.getVarType();
    int sampleSize = data.getSampleSize();
    double totalT0 = data.getSum();

    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;

    vector<int> bIndex;
    vector<int> bRange;
    double bValue = 0.0;

    pair<pair<vector<int>,vector<int>>, double> pairOut;
    for(unsigned int i=0; i<variType.size(); ++i){
        VariableInfo  variInfo = varInfo[i];

        for(auto xi : variInfo.getCombs()){
            vector<int> iIndex = xi.first;
            vector<Patient *> copyPatients(patients);

            cAllFilter.clearAllFilter();
            Filter *iNominal1;   NominalFilter  cNominal1(variInfo.getComb(iIndex)); iNominal1 = &cNominal1;
            Filter *iOrdinal1;   OrdinalFilter cOrdinal1(iIndex); iOrdinal1 = &cOrdinal1;

            if(iIndex.size()==2){
                cAllFilter.addFilter(cNominal1);
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
    }
    pairOut = make_pair(make_pair(bIndex, bRange),bValue);
    return pairOut;
}
