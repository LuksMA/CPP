#ifndef MULTICUISINECOOK_H
#define MULTICUISINECOOK_H

#include "MealBuilder.h"

class MultiCuisineCook
{
    private:
        MealBuilder *mMealBuilder;

    public:
        MultiCuisineCook();
        ~MultiCuisineCook();

        void setMealBuilder(MealBuilder *mealBuilder);
        const Meal& getMeal() ;
        void  createMeal();



};

#endif // MULTICUISINECOOK_H
