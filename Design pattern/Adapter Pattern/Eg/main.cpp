#include <iostream>
#include "Adapter.h"
#include "Adaptee.h"
#include "Target.h"

using namespace std;

int main()
{
    Adaptee * adaptee  = new Adaptee();
    Target * tar = new Adapter(adaptee);
	tar->request();

    delete adaptee;
    delete tar;
    return 0;
}

//specificRequest()|this is real Request from Adaptee!
