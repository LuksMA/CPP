#include "MultiCuisineCook.h"

MultiCuisineCook::MultiCuisineCook()
{
    mMealBuilder = nullptr;
}

MultiCuisineCook::~MultiCuisineCook()
{
    if (mMealBuilder) mMealBuilder = nullptr;
}

void MultiCuisineCook::setMealBuilder(MealBuilder *mealBuilder)
{
    if (mMealBuilder) mMealBuilder = nullptr;
    mMealBuilder = mealBuilder;
}


const Meal& MultiCuisineCook::getMeal()
{
    return mMealBuilder->getMeal();
}

void  MultiCuisineCook::createMeal()
{
    mMealBuilder->buildStarter();
    mMealBuilder->buildMainCourse();
    mMealBuilder->buildDessert();
}
