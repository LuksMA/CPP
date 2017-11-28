#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/********************************************************************************************************/

/// Functions
enum dataType { cont,    ord,    nomi   };
string getEnumType(dataType);
vector<int> uniqueValues(vector<int> &vectorIn);
template<class T>   map<vector<int>,vector<T>> mapSubsets(vector<T> &set, int varN);
map<vector<int>, vector<int>> mapSequence(vector<int> &vectIn, int varNum);
int Flip(int i){ return (i==1) ? -1:1;}
template <typename T>
std::string to_string(T value);


/********************************************************************************************************/
/// Return data type
string getEnumType(dataType d){
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

/// Return vector of unique values of a int vector
vector<int> uniqueValues(vector<int> &vectorIn){
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
map<vector<int>,vector<T>> mapSubsets(vector<T> &set, int varN){
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
map<vector<int>, vector<int>> mapSequence(vector<int> &vectIn, int varNum){
    map<vector<int>, vector<int>> mapSeq;

    int flag = 1;
    for(int i=0;i<vectIn.size();++i){
        flag = Flip(flag);
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

template <typename T>
std::string to_string(T value){
      //create an output string stream
      std::ostringstream os ;

      //throw the value into the string stream
      os << value ;

      //convert the string stream into a string and return
      return os.str() ;
}
