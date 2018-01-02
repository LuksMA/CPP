#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> loopup;
    for(int i=0;i<nums.size();++i){
        if(loopup.count(target - nums[i])){
            return {loopup[target - nums[i]],i};
        }
        loopup[nums[i]] = i;

    }

    return {};
}



template<class T>
void print1DVector(vector<T> const &vectIn);


int main()
{
    vector<int> X = {2,7,11,15};
    print1DVector(twoSum(X,9));

    return 0;
}

template<class T>
void print1DVector(vector<T> const &vectIn){
    cout<<"[ ";
    for(const auto &row : vectIn){
        cout<<row<<' ';
    }
    cout<<']';
}
