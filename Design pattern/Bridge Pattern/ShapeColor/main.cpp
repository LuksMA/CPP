#include "Shape.h"
#include "Circle.h"
#include "RedCircle.h"
#include "GreenCircle.h"
#include <iostream>

using namespace std;

int main()
{
    Shape* redCircle = new Circle(100,100, 10, new RedCircle());
    Shape* greenCircle = new Circle(100,100, 10, new GreenCircle());

    redCircle->draw();
    greenCircle->draw();

    delete redCircle;
    delete greenCircle;

    return 0;
}
