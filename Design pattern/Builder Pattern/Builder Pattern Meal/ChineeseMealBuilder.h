#ifndef CHINEESEMEALBUILDER_H
#define CHINEESEMEALBUILDER_H

#include "MealBuilder.h"

class ChineeseMealBuilder: public MealBuilder
{
public:
    ChineeseMealBuilder();
    ~ChineeseMealBuilder();

    void buildStarter();
    void buildMainCourse();
    void buildDessert();
};

#endif // CHINEESEMEALBUILDER_H
