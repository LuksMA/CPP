#include "WindowsFactory.h"

WindowsFactory::WindowsFactory()
{
    //ctor
}

WindowsFactory::~WindowsFactory()
{
    //dtor
}

Widget* WindowsFactory::create_button() {
    return new WindowsButton;
  }
  Widget* WindowsFactory::create_menu() {
    return new WindowsMenu;
  }
