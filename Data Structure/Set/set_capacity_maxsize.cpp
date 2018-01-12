#include <iostream>
#include <set>

int main () {
   int i;
   std::set<int> myset;

   if (myset.max_size()>100) {
      for (i = 0; i < 100; i++) myset.insert(i);
      std::cout << "The set contains 100 elements.\n";
   }
   else std::cout << "The set could not hold 100 elements.\n";

   return 0;
}

//The set contains 100 elements.
