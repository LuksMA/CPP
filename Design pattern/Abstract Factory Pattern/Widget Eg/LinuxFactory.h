#ifndef LINUXFACTORY_H
#define LINUXFACTORY_H

#include "Widget.h"
#include "Factory.h"
#include "LinuxMenu.h"
#include "LinuxButton.h"

class LinuxFactory : public Factory
{
    public:
        LinuxFactory();
        virtual ~LinuxFactory();
        Widget *create_button();
        Widget *create_menu();
};
#endif // LINUXFACTORY_H
