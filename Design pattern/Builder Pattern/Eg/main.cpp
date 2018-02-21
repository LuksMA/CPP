#include <iostream>
#include "ConcreteBuilder.h"
#include "Director.h"
#include "Builder.h"
#include "Product.h"

using namespace std;

int main()
{
    ConcreteBuilder* builder = new ConcreteBuilder();
    Director  director;
    director.setBuilder(builder);
    Product* pd =  director.constuct();
    pd->show();

    delete builder;
    delete pd;
    return 0;
}
//product hasA Style B Style C style
