#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		long result = 0;
		while (x) {
			result = result * 10 + x % 10;
			x /= 10;
		}
		return (result < INT_MIN || result > INT_MAX) ? 0 : result;
	}
};

int main()
{

    Solution s;
    cout<<s.reverse(1534236469);

}
