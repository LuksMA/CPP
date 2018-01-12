#include <iostream>
#include <set>

int main () {
   std::set<int> myints;
   std::cout << "0. size: " << myints.size() << '\n';

   for (int i = 0; i < 5; ++i) myints.insert(i);
   std::cout << "1. size: " << myints.size() << '\n';

   myints.insert (200);
   std::cout << "2. size: " << myints.size() << '\n';

   myints.erase(10);
   std::cout << "3. size: " << myints.size() << '\n';

   return 0;
}

//0. size: 0
//1. size: 5
//2. size: 6
//3. size: 6
