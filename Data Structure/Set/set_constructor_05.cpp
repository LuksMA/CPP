#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
   // Initializer list constructor
   std::set<std::string> fruit {
      "orange", "apple", "mango", "peach", "grape"
   };

   std::cout << "Size of set container fruit is : " << fruit.size();
   return 0;
}
