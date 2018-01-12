//Inserts new element in the set, if its unique.
#include <iostream>
#include <set>
#include <string>

int main () {
   std::set<std::string> myset;

   myset.emplace("foo");
   myset.emplace("bar");
   auto ret = myset.emplace("bar");

   std::cout << "myset contains:";
   for (std::set<std::string>::iterator it = myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   if (!ret.second) std::cout << "bar already exists in myset\n";

   return 0;
}
//myset contains: bar foo
//bar already exists in myset
