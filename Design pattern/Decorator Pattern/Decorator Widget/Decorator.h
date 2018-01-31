#ifndef DECORATOR_H
#define DECORATOR_H

#include "Widget.h"

class Decorator : public Widget
{
    public:
        Decorator(Widget *w);
        void draw();

    private:
        Widget *wid;
};

#endif // DECORATOR_H
