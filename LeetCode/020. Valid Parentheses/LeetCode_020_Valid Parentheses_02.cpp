#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char& c : s){
            if(c=='(' || c=='[' || c=='{'){
                stk.push(c);
            }
            else{
                if(stk.size()==0){
                    return false;
                }
                else{
                    char top = stk.top();
                    stk.pop();
                    if ( !( ( c==')' && top=='(' ) || (c==']' && top=='[') || (c=='}' && top=='{')) ){
                        return false;
                    }
                }
            }
        }
        return stk.size()==0;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("()");
}
