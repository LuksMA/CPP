#include "IFan.h"
#include "FanFactory.h"
#include <iostream>

using namespace std;




int main()
{
    IFan* myFan = FanFactory::createFan(ceilingfan);
    myFan->SwitchOn();

    delete myFan;
	return 0;
}
//Ceiling fan is on.
