#include <iostream>
#include <set>

main () {
   int myints[] = {10,20,30,40,50,60};
   std::set<int> first (myints,myints+3);
   std::set<int> second (myints+3,myints+6);

   first.swap(second);

   std::cout << "first contains:";
   for (std::set<int>::iterator it = first.begin(); it!=first.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   std::cout << "second contains:";
   for (std::set<int>::iterator it = second.begin(); it!=second.end(); ++it)
      std::cout << ' ' << *it;
   std::cout << '\n';

   return 0;
}

//first contains: 40 50 60
//second contains: 10 20 30
