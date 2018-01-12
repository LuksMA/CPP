// cbegin: Returns the const iterator to beginning.
// cend: Returns the const iterator to end.

#include <iostream>
#include <set>

int main () {
   std::set<int> myset = {50,40,30,20,10};

   std::cout << "myset contains:";
   for (auto it = myset.cbegin(); it != myset.cend(); ++it)
      std::cout << ' ' << *it;

   std::cout << '\n';

   return 0;
}
//myset contains: 10 20 30 40 50
