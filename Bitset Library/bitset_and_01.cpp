#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   bitset<4> b("1010");
   bitset<4> mask("1000");

   /* Turn off all bits except 3rd bit */
   b &= mask;

   cout << b << endl;

   return 0;
}

//   1010
// & 1000
// = 1000
