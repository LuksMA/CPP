#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            auto prev = res;
            res *= 10;
            res +=x%10;
            if (res / 10 != prev) {
                res = 0;
                break;
            }
            x /= 10;
        }
    return res;
    }
};

int main()
{

    Solution s;
    cout<<s.reverse(1534236469);

}



