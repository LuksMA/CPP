#ifndef LINUXMENU_H
#define LINUXMENU_H

#include "Widget.h"
class LinuxMenu : public Widget
{
    public:
        LinuxMenu();
        virtual ~LinuxMenu();
        void draw();
};

#endif // LINUXMENU_H
