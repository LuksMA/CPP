// rbegin: Returns the const reverse iterator to reverse beginning.
// rend: Returns the const reverse iterator to reverse end.

#include <iostream>
#include <set>

int main () {
   std::set<int> myset = {50,40,30,20,10};

   std::cout << "myset backwards:";
   for (auto rit = myset.crbegin(); rit != myset.crend(); ++rit)
      std::cout << ' ' << *rit;

   std::cout << '\n';

   return 0;
}
//myset backwards: 50 40 30 20 10
