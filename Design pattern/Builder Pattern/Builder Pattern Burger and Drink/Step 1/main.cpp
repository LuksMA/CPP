#include <iostream>

#include "Packing.h"
#include "Wrapper.h"
#include "Bottle.h"

using namespace std;

int main()
{
    Bottle b;
    cout<<b.pack()<<endl;
    Wrapper w;
    cout<<w.pack()<<endl;
    Packing *p = new Bottle();
    cout<<p->pack()<<endl;
    p = new Wrapper();
    cout<<p->pack()<<endl;
}
