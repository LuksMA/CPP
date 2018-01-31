#ifndef BORDERDECORATOR_H
#define BORDERDECORATOR_H

// Optional embellishment

#include "Decorator.h"

class BorderDecorator: public Decorator
{
    public:
        BorderDecorator(Widget *w): Decorator(w){};
        void draw();
};

#endif // BORDERDECORATOR_H
