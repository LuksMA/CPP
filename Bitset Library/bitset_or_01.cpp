#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   bitset<4> b("1010");
   bitset<4> mask("0101");

   /* Turn on 0th and 2nd bit */
   b |= mask;

   cout << b << endl;

   return 0;
}

//   1010
// | 0101
// = 1111
