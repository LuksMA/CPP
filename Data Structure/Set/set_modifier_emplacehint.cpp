// It returns an iterator to the newly inserted element.
#include <iostream>
#include <set>
#include <string>

int main () {
   std::set<std::string> myset;
   auto it = myset.cbegin();

   myset.emplace_hint (it,"sairam");
   it = myset.emplace_hint (myset.cend(),"krishna");
   it = myset.emplace_hint (it,"prasad");
   it = myset.emplace_hint (it,"Mammahe");

   std::cout << "myset contains:";
   for (const std::string& x: myset)
      std::cout << ' ' << x;
   std::cout << '\n';

   return 0;
}
