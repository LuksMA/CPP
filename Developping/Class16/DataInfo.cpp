#include "DataInfo.h"

DataInfo::load_DataInfo(int no, int type, vector<int> &dataSetColumn)
{
    varNo = no;
    varType = type;

    if(type==2){
        nomCuts = createSets(uniqueValues(dataSetColumn));
//        range = createNomRange(nomCuts.size());
        range = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        nomFlag = 1;
    }else if(type==1){
        range = uniqueValues(dataSetColumn);
        nomFlag = 0;
    }else if(type==0){
        range = {1,2,3,4,5,6,7,8,9,10};
        nomFlag = 0;
    }else{
        cout<<"\n Incorrect input for data type.\n";
    }

}

DataInfo::~DataInfo()
{
    //dtor
}



int DataInfo:: getVarNo(){
    return varNo;
}

int DataInfo:: getType(){
    return varType;
}

bool DataInfo:: nomContains(int x,int index){
    if(nomCuts[index].count(x)){
        return true;
    }else{
        return false;
    }

}
int DataInfo:: getCutSize(){
    if(varType==2){
        return nomCuts.size();
    }else{
        return range.size();
    }
}


/// Return vector of unique values of a int vector
vector<int> DataInfo :: uniqueValues(vector<int> &vectorIn){
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


vector<set<int>> DataInfo :: createSets(vector<int> setIn){
    vector<set<int>> out;

	int max = 1 << setIn.size();
	for(int i = 0; i < max; i++) {
		set<int> Second;

		int j = i;
		int index = 0;
		while (j > 0) {
			if((j & 1) > 0)
				Second.insert(setIn[index]);
                j >>= 1;
                index++;
		}
		if(Second.size()<=setIn.size()/2){
            out.push_back(Second);
		}
	}
	return out;
}


vector<int> DataInfo :: createNomRange(int x){
    vector<int> out;
    for(int i=0; i<x; ++i){
        out.push_back(i);
    }
    return out;
}


