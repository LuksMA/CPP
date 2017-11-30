#include "VariableInfo.h"

VariableInfo :: VariableInfo(int no, int type, vector<int> &dataSetColumn){
    varNo = no;
    varType = type;
    map<vector<int>, vector<int>> mapDict;

    if(type==2){
        vector<int> uni = uniqueValues(dataSetColumn);
        cuts = seq(10);
        mapDict = mapSubsets(uni,no);
    }else if(type==1){
        vector<int> uni = uniqueValues(dataSetColumn);
        cuts = seq(uni.size());
        mapDict = mapSequence(uni,no);
    }else if(type==0){
        vector<int> uni = {0,1,2,3,4,5,6,7,8,9};
        cuts = seq(10);
        mapDict = mapSequence(uni,no);
    }else{
        cout<<"\nIn correct input for data type.\n";
    }
    searchSets = mapDict;
}

VariableInfo :: ~VariableInfo()
{
    //dtor
}


int VariableInfo :: getVarNo(){ return varNo;   }
int VariableInfo :: getVarType(){ return varType;   }

int VariableInfo :: getCombSize(){    return searchSets.size();   }
vector<int> VariableInfo :: getComb(vector<int> vectIn) {
    if(varType==2){
        vector<int> add = searchSets[vectIn];
        vectIn.insert(vectIn.end(),add.begin(),add.end());
        return vectIn;
    }else{
        return searchSets[vectIn];
    }
}
map<vector<int>, vector<int>> VariableInfo :: getCombs(){ return searchSets; }

void VariableInfo :: printVarInfo(){
    cout<<"Variable number: "<<getVarNo()<<"\tType: "<<getEnumType(dataType(getVarType()))<<endl;
    cout<<getCombSize()<<" available combinations:"<<endl;
    if(varType==2){
        printNominalMap(searchSets);
    }else{
        printOrdinalMap(searchSets);
    }
}



unordered_map<int,int> VariableInfo :: getCuts(){
    return cuts;
}

void VariableInfo :: printCuts(){
    printUnorderedMap(cuts);
}
void VariableInfo :: printComb(vector<int> &vectIn){
    print1DVector(getComb(vectIn));
}

template<class T>
void VariableInfo :: printUnorderedMap(unordered_map<T,T> &mapIn){
    for( const auto& x : mapIn ){
        cout<<"<"<<x.first<<" "<<x.second<<">"<<endl;
    }
}

/// Return vector of unique values of a int vector
vector<int> VariableInfo :: uniqueValues(vector<int> &vectorIn){
    if(!vectorIn.empty()){
        sort(vectorIn.begin(), vectorIn.end());
        vector<int>::iterator it;
        it = unique (vectorIn.begin(), vectorIn.end());
        vectorIn.resize(distance(vectorIn.begin(),it));
    }else{
        cout<<"Warning: Empty vector detected. Please initialize vector."<<endl;
    }
    return vectorIn;
}


/// Return map of all possible subsets of given unique values (associate with variable number)
/// For nominal variable
template<class T>
map<vector<int>,vector<T>> VariableInfo :: mapSubsets(vector<T> &set, int varN){
    map <vector<int>,vector<T>> mapOfCategorical;

	int max = 1 << set.size();
	for(int i = 0; i < max; i++) {
        vector<int> First;

		vector<T> Second;
		int j = i;
		int index = 0;
		while (j > 0) {
			if((j & 1) > 0)
				Second.push_back(set[index]);
                j >>= 1;
                index++;
		}
		if(!Second.empty()){
		    First.push_back(varN);
            First.push_back(i);
            mapOfCategorical.insert(make_pair(First,Second));
		}
	}
	return mapOfCategorical;
}


/// Return map of all possible cut of given unique values (associate with variable number)
/// For ordinal variable
map<vector<int>, vector<int>> VariableInfo :: mapSequence(vector<int> &vectIn, int varNum){
    map<vector<int>, vector<int>> mapSeq;

    int flag = 1;
    for(int i=0;i<vectIn.size();++i){
        flag = flip(flag);
        int index = i+1;
        if(flag==-1){
            vector<int> tempSecond(vectIn.begin(),vectIn.begin()+index);
            if(!tempSecond.empty()){
                vector<int> tempFirst ={varNum,i+1,flag};
                mapSeq.insert(make_pair(tempFirst,tempSecond));
            }
            i--;
        }else{
            vector<int> tempSecond(vectIn.begin()+index,vectIn.end());
            if(!tempSecond.empty()){
                vector<int> tempFirst ={varNum,i+1,flag};
                mapSeq.insert(make_pair(tempFirst,tempSecond));
            }
        }
    }
    return mapSeq;
}

unordered_map<int,int> VariableInfo :: VariableInfo :: seq(int n){
    unordered_map<int,int> mapOut;
    for(unsigned i=1;i<=n;++i){
        mapOut[i] = varNo;
    }
    return mapOut;
}

int VariableInfo :: flip(int i){ return (i==1) ? -1:1;}




template<class T>
void VariableInfo :: printNominalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
        cout<<'<'<<First[0]<<' '<<First[1]<<"> :: ";
        vector<int> Second = x.second;
        print1DVector(Second);cout<<'\n';
    }
}

template<class T>
void VariableInfo :: printOrdinalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
//        cout<<"Ordinal variable "<<First[0]<<", with cut "<<First[1]<<",  (1 for >=, -1 for <) "<<First[2]<<": ";
        cout<<'<'<<First[0]<<' '<<First[1]<<' '<<First[2]<<"> :: ";
        vector<int> Second = x.second;
        print1DVector(Second);cout<<'\n';
    }
}

template<class T>
void VariableInfo :: print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}


string VariableInfo :: getEnumType(dataType d){
    switch(d){
        case cont:
            return "Continuous";
        case ord:
            return "Ordinal";
        case nomi:
            return "Nominal";
        default:
            return "You typed something wrong!";
    }
}
