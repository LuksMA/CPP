#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   bitset<4> b("0000");

   cout << ~b << endl;

   return 0;
}

//1111
