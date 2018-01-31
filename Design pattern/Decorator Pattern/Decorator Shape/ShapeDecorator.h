#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

class ShapeDecorator: public Shape
{
    public:
        ShapeDecorator(Shape* decoratedShape);
        void draw();

    protected:
        Shape* decoratedShape;

};

#endif // SHAPEDECORATOR_H
