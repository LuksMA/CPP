#ifndef REDSHAPEDECORATOR_H
#define REDSHAPEDECORATOR_H

#include "ShapeDecorator.h"

class RedShapeDecorator : public ShapeDecorator
{
    public:
        RedShapeDecorator(Shape* s): ShapeDecorator(s){};
        void draw();
    private:
        void setRedBorder(Shape* decoratedShape);

};

#endif // REDSHAPEDECORATOR_H
