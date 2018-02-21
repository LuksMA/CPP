#include "Client.h"
#include "Factory.h"
#include "LinuxFactory.h"
#include "WindowsFactory.h"
#include <iostream>
#define LINUX
using namespace std;

int main()
{
    Factory *factory;
#ifdef LINUX
    factory = new LinuxFactory;
#else  // WINDOWS
    factory = new WindowsFactory;
#endif

    Client *c = new Client(factory);
    c->draw();
}

//LinuxButton
//LinuxButton
//LinuxMenu
//LinuxMenu
//LinuxButton
