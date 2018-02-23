#include "Adaptee.h"

Adaptee::Adaptee()
{
    //ctor
}

Adaptee::~Adaptee()
{
    //dtor
}

void Adaptee::specificRequest(){
	cout << "specificRequest()|this is real Request from Adaptee!" << endl;
}
