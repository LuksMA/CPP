#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   bitset<4> b("1010");
   bitset<4> mask("1111");

   /* Invert each bit of bitset b */
   b ^= mask;

   cout << b << endl;

   return 0;
}

//   1010
// ^ 1111
// = 0101

