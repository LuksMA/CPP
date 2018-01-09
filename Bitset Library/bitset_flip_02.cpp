#include <iostream>
#include <bitset>

using namespace std;

int main(void) {

   bitset<4> b("1010");

   cout << "Before flip operation b = " << b << endl;

   b.flip();

   cout << "After flip operation b = " << b << endl;

   return 0;
}

//Before flip operation b = 1010
//After flip operation b = 0101
