#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RedShapeDecorator.h"
#include <iostream>

using namespace std;

int main()
{
    Shape* circle = new Circle();
    Shape* redCircle = new RedShapeDecorator(new Circle());
    Shape* redRectangle = new RedShapeDecorator(new Rectangle());

    cout<<"Circle with normal border"<<endl;
    circle->draw();

    cout<<"\nCircle of red border"<<endl;
    redCircle->draw();

    cout<<"\nRectangle of red border"<<endl;
    redRectangle->draw();
}


//Circle with normal border
//Shape: Circle
//
//Circle of red border
//Shape: Circle
//Border Color: Red
//
//Rectangle of red border
//Shape: Rectangle
//Border Color: Red
