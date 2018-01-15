#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, -1);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n-1) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
}

template<class T>
void print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}

int main(){
    vector<vector<int>> X = combine(5,3);
    int i = 0;
    for(auto x:X){
        cout<<i++<<": ";print1DVector(x);cout<<endl;
    }
}
