#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s("hello");
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });

    std::vector<size_t> ordinals;
    std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
                   [](unsigned char c) -> size_t { return static_cast<size_t>(c); });

    std::cout << s << ':';
    for (size_t ord : ordinals) {
       std::cout << ' ' << ord;
    }
}
