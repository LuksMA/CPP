#include <iostream>
#include <set>

int main () {
   std::set<int> myset;
   std::set<int>::iterator it;

   for (int i = 1; i < 10; i++) myset.insert(i*20);

   it = myset.begin();
   ++it;

   myset.erase (it);

   myset.erase (80);

   it = myset.find (60);
   myset.erase (it, myset.end());

   std::cout << "myset contains:";
   for (it = myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   return 0;
}

//myset contains: 20
