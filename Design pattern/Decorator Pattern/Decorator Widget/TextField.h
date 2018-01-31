#ifndef TEXTFIELD_H
#define TEXTFIELD_H

// "Core" class

#include "Widget.h"

class TextField : public Widget
{
    public:
        TextField(int w, int h);
        void draw();
    private:
        int width, height;
};

#endif // TEXTFIELD_H
