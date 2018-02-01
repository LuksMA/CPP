#include "Pizza.h"
#include "Margherita.h"
#include "FarmHouse.h"
#include "FreshTomato.h"
#include "Paneer.h"
#include <iostream>

using namespace std;

int main()
{
    Pizza* pizza1 = new Margherita();
    cout<<pizza1->getDescription()<<" Cost: "<<pizza1->getCost()<<endl;

    Pizza* pizza2 = new Paneer(new FreshTomato(new FarmHouse()));
    cout<<pizza2->getDescription()<<" Cost: "<<pizza2->getCost()<<endl;
}
