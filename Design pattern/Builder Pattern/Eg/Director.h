#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"

class Director
{
public:
    Director();
    virtual ~Director();

    Product* constuct();
    void setBuilder(Builder* buider);


private:
    Builder* m_pbuilder;
};

#endif // DIRECTOR_H
