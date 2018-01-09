#include <iostream>
#include <bitset>

using namespace std;

int main(void) {

   bitset<4> b("0001");

   auto result = b << 1;

   cout << result << endl;

   return 0;
}
//0010
