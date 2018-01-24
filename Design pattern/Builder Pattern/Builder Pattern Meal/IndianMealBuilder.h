#ifndef INDIANMEALBUILDER_H
#define INDIANMEALBUILDER_H

#include "MealBuilder.h"
class IndianMealBuilder: public MealBuilder
{
public:
    IndianMealBuilder();
    ~IndianMealBuilder();

    void buildStarter();
    void buildMainCourse();
    void buildDessert();
};

#endif // INDIANMEALBUILDER_H
