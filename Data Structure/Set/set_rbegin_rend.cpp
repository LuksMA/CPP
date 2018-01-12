// rbegin: Returns the reverse iterator to reverse beginning.
// rend: Returns the reverse iterator to reverse end.
#include <iostream>
#include <set>

int main () {
   int myints[] = {20,40,60,80,100};
   std::set<int> myset (myints,myints+10);

   std::set<int>::reverse_iterator rit;

   std::cout << "myset contains:";
   for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
      std::cout << ' ' << *rit;

   std::cout << '\n';

   return 0;
}

//myset contains: 2130567168 4201307 2686824 2686800 100 80 60 40 20
