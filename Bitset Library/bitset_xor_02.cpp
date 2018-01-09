#include <iostream>
#include <bitset>

using namespace std;

int main(void) {

   bitset<4> b("1010");
   bitset<4> mask("0101");

   /* Turn on all bits */
   auto result = b ^ mask;

   cout << result << endl;

   return 0;
}

//   1010
// ^ 0101
// = 1111

