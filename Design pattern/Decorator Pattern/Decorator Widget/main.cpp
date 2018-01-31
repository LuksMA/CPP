#include "Widget.h"
#include "TextField.h"
#include "BorderDecorator.h"
#include "ScrollDecorator.h"

#include <iostream>

using namespace std;

int main()
{
    Widget *aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator(new TextField(80, 24))));
    aWidget->draw();
}

//TextField: 80, 24
//   ScrollDecorator
//   BorderDecorator
//   BorderDecorator
