#include <iostream>
#include <bitset>

using namespace std;

int main(void) {

   bitset<4> b("1110");

   cout << "Before flip operation b = " << b << endl;

   b.flip(1);

   cout << "After flip operation b = " << b << endl;

   return 0;
}

//Before flip operation b = 1110
//After flip operation b = 1100
