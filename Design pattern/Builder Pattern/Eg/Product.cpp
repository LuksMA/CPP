#include "Product.h"

Product::Product()
{
    //ctor
}

Product::~Product()
{
    //dtor
}

void Product::setA(string str)
{
	m_a = str;
}

void Product::setB(string str)
{
	m_b = str;
}

void Product::setC(string str)
{
	m_c = str;
}

void Product::show()
{
	cout << "product has" << m_a << m_b << m_c << endl;
}
