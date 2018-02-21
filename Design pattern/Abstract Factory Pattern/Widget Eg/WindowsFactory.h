#ifndef WINDOWSFACTORY_H
#define WINDOWSFACTORY_H

#include "Widget.h"
#include "Factory.h"
#include "WindowsButton.h"
#include "WindowsMenu.h"

class WindowsFactory : public Factory
{
    public:
        WindowsFactory();
        virtual ~WindowsFactory();
        Widget *create_button();
        Widget *create_menu();
};

#endif // WINDOWSFACTORY_H
