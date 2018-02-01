#include "I.h"
#include "A.h"
#include "X.h"
#include "Y.h"
#include "Z.h"

#include <iostream>

using namespace std;

int main()
{
  I *anX = new X(new A);
  I *anXY = new Y(new X(new A));
  I *anXYZ = new Z(new Y(new X(new A)));

  anX->do_it();cout << '\n';       //  AX
  anXY->do_it();cout << '\n';      // AXY
  anXYZ->do_it();cout << '\n';     // AXYZ
  delete anX;
  delete anXY;
  delete anXYZ;
}
//AX
//AXY
//AXYZ
//X dtor   A dtor
//Y dtor   X dtor   A dtor
//Z dtor   Y dtor   X dtor   A dtor
