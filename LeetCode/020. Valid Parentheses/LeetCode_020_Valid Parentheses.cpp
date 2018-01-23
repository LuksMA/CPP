#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++) {
            if(isLeft(s[i])) {
                stk.push(s[i]);
            }
            else {
                if(stk.empty() || !isClose(stk.top(),s[i]))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }

    bool isLeft(char a) {
        return (a=='(' || a=='{' || a=='[');
    }

    bool isClose(char a, char b) {
        if(a=='(') return b==')';
        if(a=='[') return b==']';
        if(a=='{') return b=='}';
        return false;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("()");
}
