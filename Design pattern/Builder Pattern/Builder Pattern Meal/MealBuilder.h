#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include "Meal.h"

class MealBuilder
{
    protected:
        Meal mMeal;

    public:
        MealBuilder();
        ~MealBuilder();

        const Meal& getMeal() { return mMeal; }
        virtual void buildStarter() = 0;
        virtual void buildMainCourse() = 0;
        virtual void buildDessert() = 0;
};

#endif // MEALBUILDER_H
