#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class TwoSum{
    private:
        unordered_map<int,int> lookup;
    public:
        void add(int i){
            ++lookup[i];
        }
        bool find(int target){
            for(auto x:lookup){
                if(lookup.count(target - x.first)){
                    return true;
                }
            }
            return false;
        }

};


int main(){
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(5);

    cout<<ts.find(4)<<endl;  // 1
    cout<<ts.find(7)<<endl;  // 0

}
