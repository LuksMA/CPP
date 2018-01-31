#ifndef SCROLLDECORATOR_H
#define SCROLLDECORATOR_H

// Optional embellishment

#include "Decorator.h"

class ScrollDecorator: public Decorator
{
    public:
        ScrollDecorator(Widget *w): Decorator(w){};
        void draw();
};

#endif // SCROLLDECORATOR_H
