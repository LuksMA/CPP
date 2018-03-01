#include "Circle.h"

Circle::Circle(int x, int y, int radius, DrawAPI* drawAPI):Shape(drawAPI)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw()
{
    drawAPI->drawCircle(radius,x,y);
}
