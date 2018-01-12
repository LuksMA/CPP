#include <iostream>
#include <set>

int main () {
   std::set<int> myset;

   myset.insert (10);
   myset.insert (20);
   myset.insert (30);

   std::cout << "myset contains:";
   for (std::set<int>::iterator it = myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   myset.clear();
   myset.insert (111);
   myset.insert (222);

   std::cout << "myset contains:";
   for (std::set<int>::iterator it = myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   return 0;
}


//myset contains: 10 20 30
//myset contains: 111 222
