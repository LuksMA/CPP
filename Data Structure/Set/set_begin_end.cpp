// begin: Returns the iterator to beginning.
// end: Returns the iterator to end.
#include <iostream>
#include <set>

int main () {
   int myints[] = {50,40,30,20,10};
   std::set<int> myset (myints,myints+10);

   std::cout << "myset contains:";
   for (std::set<int>::iterator it = myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;

   std::cout << '\n';

   return 0;
}
//myset contains: 10 20 30 40 50 2686800 2686824 4199048 4201275 2130567168
