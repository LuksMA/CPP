#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
   const char *s = "1100";

   bitset<4> b(s);

   cout << b << endl;

   return 0;
}
//1100
