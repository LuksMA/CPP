/***************************************************************************************************************************************/
pair<pair<vector<int>,vector<int>>, double> OneDepth(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients);
void OneDepthPrint(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients);
pair<pair<vector<vector<int>>,vector<vector<int>>>, double> TwoDepth(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients);
void TwoDepthPrint(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients);







/***************************************************************************************************************************************/
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


void TwoDepthPrint(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients){
    int num = 0;
    vector<int> variType = data.getVarType();
    int sampleSize = data.getSampleSize();
    double totalT0 = data.getSum();
    pair<pair<vector<vector<int>>,vector<vector<int>>>, double> pairOut;

    vector<int> bIndexI;
    vector<int> bIndexJ;
    vector<int> bRangeI;
    vector<int> bRangeJ;
    double bValue = 0;


    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;

    for(int i=0; i<data.getCovariateSize(); ++i){  /// loop1
        VariableInfo  variInfoI = varInfo.at(i);

        for(int j=i+1; j<data.getCovariateSize(); ++j){   /// loop2
            VariableInfo  variInfoJ = varInfo.at(j);
            vector<int> bIndexIVar;
            vector<int> bIndexJVar;
            vector<int> bRangeIVar;
            vector<int> bRangeJVar;
            double bValueVar = 0;

            for(auto xi : variInfoI.getCombs()){   /// loop3
                vector<int> FirstI = xi.first;
                vector<int> SecondI = xi.second;

                for(auto xj :variInfoJ.getCombs()){   /// loop4
                    vector<int> FirstJ = xj.first;
                    vector<int> SecondJ = xj.second;

                    vector<Patient *> copyPatients(patients);

                    cAllFilter.clearAllFilter();

                    Filter *iNominal1;   NominalFilter  cNominal1(variInfoI.getComb(FirstI)); iNominal1 = &cNominal1;
                    Filter *iOrdinal1;   OrdinalFilter cOrdinal1(FirstI); iOrdinal1 = &cOrdinal1;
                    Filter *iNominal2;   NominalFilter  cNominal2(variInfoJ.getComb(FirstJ)); iNominal2 = &cNominal2;
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

                    cActionT1.meetCriteria(cAllFilter.meetCriteria(copyPatients));
                    double currentExp = (cActionT1.getSumT1()+(totalT0-cActionT1.getSumT0()))*2/sampleSize;
                    if(currentExp > bValueVar){
                        bValueVar = currentExp;
                        bRangeIVar = SecondI;
                        bIndexIVar = FirstI;
                        bRangeJVar = SecondJ;
                        bIndexJVar = FirstJ;
                    }
                    if(currentExp > bValue){
                        bValue = currentExp;
                        bRangeI = SecondI;
                        bIndexI = FirstI;
                        bRangeJ = SecondJ;
                        bIndexJ = FirstJ;
                    }
                    cActionT1.resetSum();
                }/// loop4
            }/// loop3
             cout<<num++<<": "<<bValueVar<<'\t';print1DVector(bIndexIVar);print1DVector(bIndexJVar);
             cout<<" \t";print1DVector(bRangeIVar);print1DVector(bRangeJVar);cout<<"\n";
             vector<vector<int>> indices; indices.push_back(bIndexI);indices.push_back(bIndexJ);
             vector<vector<int>> ranges; ranges.push_back(bRangeI);ranges.push_back(bRangeJ);
             pairOut = make_pair(make_pair(indices, ranges),bValue);

        }/// loop 2
    }///loop 1
    cout<<"Best:\n"<<pairOut.second;
    cout<<"\tIndex: ";print1DVector(pairOut.first.first[0]);print1DVector(pairOut.first.first[1]);
    cout<<"\tRange: ";print1DVector(pairOut.first.second[0]);print1DVector(pairOut.first.second[1]);
    cout<<endl;
}



pair<pair<vector<vector<int>>,vector<vector<int>>>, double> TwoDepth(DataGeneration data, vector<VariableInfo> varInfo, vector<Patient *> patients){
    vector<int> variType = data.getVarType();
    int sampleSize = data.getSampleSize();
    double totalT0 = data.getSum();
    pair<pair<vector<vector<int>>,vector<vector<int>>>, double> pairOut;

    vector<int> bIndexI;
    vector<int> bIndexJ;
    vector<int> bRangeI;
    vector<int> bRangeJ;
    double bValue = 0;


    Filter *iActionT1;  ActionFilter cActionT1({1});    iActionT1 = &cActionT1;
    Filter *iAllFilter;  AllFilter cAllFilter;  iAllFilter = &cAllFilter;

    for(int i=0; i<data.getCovariateSize(); ++i){  /// loop1
        VariableInfo  variInfoI = varInfo.at(i);

        for(int j=i+1; j<data.getCovariateSize(); ++j){   /// loop2
            VariableInfo  variInfoJ = varInfo.at(j);

            for(auto xi : variInfoI.getCombs()){   /// loop3
                vector<int> FirstI = xi.first;
                vector<int> SecondI = xi.second;

                for(auto xj :variInfoJ.getCombs()){   /// loop4
                    vector<int> FirstJ = xj.first;
                    vector<int> SecondJ = xj.second;

                    vector<Patient *> copyPatients(patients);

                    cAllFilter.clearAllFilter();

                    Filter *iNominal1;   NominalFilter  cNominal1(variInfoI.getComb(FirstI)); iNominal1 = &cNominal1;
                    Filter *iOrdinal1;   OrdinalFilter cOrdinal1(FirstI); iOrdinal1 = &cOrdinal1;
                    Filter *iNominal2;   NominalFilter  cNominal2(variInfoJ.getComb(FirstJ)); iNominal2 = &cNominal2;
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

                    cActionT1.meetCriteria(cAllFilter.meetCriteria(copyPatients));
                    double currentExp = (cActionT1.getSumT1()+(totalT0-cActionT1.getSumT0()))*2/sampleSize;
                    if(currentExp > bValue){
                        bValue = currentExp;
                        bRangeI = SecondI;
                        bIndexI = FirstI;
                        bRangeJ = SecondJ;
                        bIndexJ = FirstJ;
                    }
                    cActionT1.resetSum();
                }/// loop4
            }/// loop3
             vector<vector<int>> indices; indices.push_back(bIndexI);indices.push_back(bIndexJ);
             vector<vector<int>> ranges; ranges.push_back(bRangeI);ranges.push_back(bRangeJ);
             pairOut = make_pair(make_pair(indices, ranges),bValue);

        }/// loop 2
    }///loop 1
    return pairOut;
}
