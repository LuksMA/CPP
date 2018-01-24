#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include "Meal.h"
#include "VegBurger.h"
#include "ChickenBurger.h"
#include "Coke.h"
#include "Pepsi.h"

class MealBuilder
{
    public:
        MealBuilder();
        ~MealBuilder();

    Meal* prepareVegMeal();
    Meal* prepareNonVegMeal();
};

#endif // MEALBUILDER_H
