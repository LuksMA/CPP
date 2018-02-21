#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>

using namespace std;

class Widget
{
    public:
        Widget();
        virtual ~Widget();
        virtual void draw() = 0;
};

#endif // WIDGET_H
