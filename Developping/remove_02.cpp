#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> b{ "the", "of" };
    std::vector<std::string> a{ "oranges", "the", "of", "apples" };

    auto pred = [&b](const std::string& key) ->bool
    {
        return std::find(b.begin(), b.end(), key) != b.end();
    };

    a.erase(std::remove_if(a.begin(), a.end(), pred), a.end());

    std::cout << a.at(0) << "\n";
    std::cout << a.at(1) << "\n";
}
