#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   bitset<4> b1("1010");
   bitset<4> b2("1010");

   if (b1 == b2)
      cout << "Both bitsets are equal." << endl;
   b1 >>= 1;

   if (!(b1 == b2))
      cout << "Both bitsets are not equal." << endl;

   return 0;
}


//Both bitsets are equal.
//Both bitsets are not equal.
