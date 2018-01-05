#include <iostream>

using namespace std;

class Solution {
    int calcSum(int n){
        int sum = 0;
        while(n){
            int num = n % 10;
            sum += num * num;
            n /= 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
       int slow = n, fast = n;
       do{
           slow = calcSum(slow);
           fast = calcSum(fast);
           fast = calcSum(fast);
       } while(slow != fast);

        return slow == 1 ? true : false;
    }
};

int main(){
    Solution s;
    cout<<s.isHappy(19);
}
