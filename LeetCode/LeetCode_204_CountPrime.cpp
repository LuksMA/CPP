#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        vector<bool> passed(n, false);
        int res = 1;
        for(int i = 3; i < n; i+=2) { //NO need checking even number
            if(!passed[i]) {
                res++;
                for(long long j = (long long)i*i; j < n; j+=2*i) //NO need checking even number e.g, j = (i+1)*i as i is odd number
                    passed[j] = true;
            }
        }
        return res;
    }
};


int main()
{
    Solution s;
    cout<<s.countPrimes(10);

}
