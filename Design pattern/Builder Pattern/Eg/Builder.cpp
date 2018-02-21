#include "Builder.h"

Builder::Builder()
{
    m_prod = new Product();
}

Builder::~Builder()
{
    //dtor
}

Product* Builder::getResult(){
	return m_prod;
}
