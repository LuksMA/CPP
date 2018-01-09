#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   bitset<4> b1("1010");
   bitset<4> b2("1110");

   if (b1 != b2)
      cout << "Both bitsets are not equal." << endl;

   b1 = b2;

   if (!(b1 != b2))
      cout << "Both bitsets are equal." << endl;

   return 0;
}

//Both bitsets are not equal.
//Both bitsets are equal.
