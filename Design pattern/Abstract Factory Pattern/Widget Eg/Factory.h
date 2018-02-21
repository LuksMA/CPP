#ifndef FACTORY_H
#define FACTORY_H

#include "Widget.h"
class Factory
{
    public:
        Factory();
        virtual ~Factory();
        virtual Widget *create_button() = 0;
        virtual Widget *create_menu() = 0;
};

#endif // FACTORY_H
