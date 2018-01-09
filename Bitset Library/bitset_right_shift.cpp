#include <iostream>
#include <bitset>

using namespace std;

int main(void) {

   bitset<4> b("1000");

   b >>= 1;

   cout << b << endl;

   return 0;
}

//0100
