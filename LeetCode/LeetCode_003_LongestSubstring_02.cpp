#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> charMap;
    int start = -1;
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (charMap.count(s[i]) != 0)
        {
            start = max(start, charMap[s[i]]);
        }
        charMap[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }

    return maxLen;
}

int main()
{
    string s = "abcabcbb";

    cout<<lengthOfLongestSubstring(s);



}
