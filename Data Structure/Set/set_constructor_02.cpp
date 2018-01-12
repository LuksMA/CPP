// Array to set
#include <iostream>
#include <set>

using namespace std;

int main(void) {
   char vowels[] = {'a','e','i','o','u'};

   // Range Constructor
   std::set<char> t_set (vowels, vowels+5);

   std::cout << "Size of set container t_set is : " << t_set.size();
   return 0;
}
