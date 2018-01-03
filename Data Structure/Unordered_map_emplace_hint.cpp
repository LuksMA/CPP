#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    unordered_map<char, int> um =
    {
        {'b', 2},
        {'c', 3},
        {'d', 4},
    };
    cout << "Original Unordered map contains following elements" << endl;
    for (auto it = um.cbegin(); it != um.cend(); ++it)
        cout << it->first << " = " << it->second << endl;

    cout << "\nUnordered map contains following elements" << endl;
    um.emplace_hint(um.end(), 'e', 5);
    for (auto it = um.cbegin(); it != um.cend(); ++it)
        cout << it->first << " = " << it->second << endl;

    um.emplace_hint(um.begin(), 'a', 1);
    cout << "\nUnordered map contains following elements" << endl;

    for (auto it = um.cbegin(); it != um.cend(); ++it)
        cout << it->first << " = " << it->second << endl;

    return 0;
}



//Original Unordered map contains following elements
//d = 4
//b = 2
//c = 3
//
//Unordered map contains following elements
//e = 5
//d = 4
//b = 2
//c = 3
//
//Unordered map contains following elements
//a = 1
//e = 5
//d = 4
//b = 2
//c = 3
