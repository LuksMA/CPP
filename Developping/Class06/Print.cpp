#include <vector>
#include <map>
#include <iostream>

using namespace std;

/********************************************************************************************************/
template<class T>   void printNum(T x);
template<class T>   void print1DVector(vector<T> const &vectIn);
template<class T>   void print2DVector(vector<vector<T>> const &vectIn);
template<class T>   void printNominalMap(map<vector<int>,vector<T>> &mapIn);
template<class T>   void printOrdinalMap(map<vector<int>,vector<T>> &mapIn);
void printPair(pair<vector<int> , vector<int>> pairIn);
void printPair2(pair<vector<vector<int>>,vector<vector<int>>> pairIn);
/********************************************************************************************************/


template<class T>
void printNum(T x){
    cout<<x<<endl;
}

template<class T>
void print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}

template<class T>
void print2DVector(vector<vector<T>> const &vectIn){
    try {
        for(unsigned int j=0;j<vectIn.at(0).size();++j){
            for(unsigned int i=0;i<vectIn.size();++i){
                cout<<vectIn[i][j]<<' ';
            }
            cout<<endl;
        }
    }catch (const std::out_of_range& oor) {
        cerr << "Out of Range error in print2DVector. Please check empty input: " << oor.what() << '\n';
    }
}

template<class T>
void printNominalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
        cout<<'<'<<First[0]<<' '<<First[1]<<"> :: ";
        vector<int> Second = x.second;
        print1DVector(Second);cout<<'\n';
    }
}

template<class T>
void printOrdinalMap(map<vector<int>,vector<T>> &mapIn){
    for( const auto& x : mapIn ){
        vector<int> First = x.first;
//        cout<<"Ordinal variable "<<First[0]<<", with cut "<<First[1]<<",  (1 for >=, -1 for <) "<<First[2]<<": ";
        cout<<'<'<<First[0]<<' '<<First[1]<<' '<<First[2]<<"> :: ";
        vector<int> Second = x.second;
        print1DVector(Second);cout<<'\n';
    }
}

void printPair(pair<vector<int> , vector<int>> pairIn){
    print1DVector(pairIn.first);cout<<'\t';
    print1DVector(pairIn.second);cout<<'\t';
}

void printPair2(pair<vector<vector<int>>,vector<vector<int>>> pairIn){
    print2DVector(pairIn.first);cout<<'\t';
    print2DVector(pairIn.second);cout<<'\t';
}
