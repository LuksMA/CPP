#include <iostream>
#include <set>

int main () {
   std::set<int> myset;

   myset.insert(0);
   myset.insert(10);
   myset.insert(20);

   std::cout << "myset contains:";
   while (!myset.empty()) {
      std::cout << ' ' << *myset.begin();
      myset.erase(myset.begin());
   }
   std::cout << '\n';

   return 0;
}

//myset contains: 0 10 20
