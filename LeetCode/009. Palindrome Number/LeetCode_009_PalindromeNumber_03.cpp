#include <iostream>

using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        //int b = 10; while (x / b) b *= 10; b /= 10;
        //if (x/ b != x % 10) return false;
        //x = (x % b) / 10;
        int l = x, r = 0;
        while (l) r = r * 10 + l % 10, l /= 10;
        return r == x;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(121);
}
