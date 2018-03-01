#ifndef SHAPE_H
#define SHAPE_H

#include "DrawAPI.h"

class Shape
{
    public:
        Shape(DrawAPI* drawAPI);
        virtual ~Shape();

        virtual void draw() = 0;

    protected:
        DrawAPI* drawAPI;
};

#endif // SHAPE_H
