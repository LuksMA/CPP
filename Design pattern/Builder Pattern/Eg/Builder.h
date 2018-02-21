#ifndef BUILDER_H
#define BUILDER_H

#include "Product.h"
class Builder
{
    public:
	Builder();
	virtual ~Builder();

	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	virtual Product * getResult();

    protected:
    	Product* m_prod;
};

#endif // BUILDER_H
