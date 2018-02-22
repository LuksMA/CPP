#include <iostream>
#include "Singleton.h"
using namespace std;

int main()
{
    Singleton * sg = Singleton::getInstance();
	sg->singletonOperation();

    return 0;
}

//singletonOperation
