#include <iostream>
#include <bitset>

using namespace std;

int main(void) {

   bitset<4> b("1010");
   bitset<4> mask("1000");

   /* Trun off all bits except 3rd bit */
   auto result = b & mask;

   cout << result << endl;

   return 0;
}
