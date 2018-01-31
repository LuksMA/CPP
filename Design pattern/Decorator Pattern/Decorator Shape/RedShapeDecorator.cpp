#include "RedShapeDecorator.h"


void RedShapeDecorator::draw(){
    decoratedShape->draw();
    setRedBorder(decoratedShape);
}

void RedShapeDecorator::setRedBorder(Shape* decoratedShape){
    cout<<"Border Color: Red"<<endl;
}
