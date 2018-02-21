#include "LinuxFactory.h"

LinuxFactory::LinuxFactory()
{
    //ctor
}

LinuxFactory::~LinuxFactory()
{
    //dtor
}

Widget* LinuxFactory::create_button()
{
    return new LinuxButton;
}

Widget* LinuxFactory::create_menu()
{
    return new LinuxMenu;
}
