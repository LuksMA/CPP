#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(void) {
   string s = "1100";
   bitset<4>b(s);

   cout << b << endl;

   return 0;
}

//1100
