#ifndef MEXICANMEALBUILDER_H
#define MEXICANMEALBUILDER_H

#include "MealBuilder.h"

class MexicanMealBuilder: public MealBuilder
{
    public:
        MexicanMealBuilder();
        ~MexicanMealBuilder();

    void buildStarter();
    void buildMainCourse();
    void buildDessert();

};

#endif // MEXICANMEALBUILDER_H
