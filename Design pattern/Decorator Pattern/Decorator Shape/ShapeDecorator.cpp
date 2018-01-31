#include "ShapeDecorator.h"

ShapeDecorator::ShapeDecorator(Shape* decoratedShape)
{
    this->decoratedShape = decoratedShape;
}

void ShapeDecorator :: draw(){
    decoratedShape->draw();
}
