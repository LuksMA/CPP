#include "Meal.h"

Meal::Meal()
{
    //ctor
}

Meal::~Meal()
{
    //dtor
}

void Meal::setMealItem(string mealItem)
{
    mMeal.push(mealItem);
}

void Meal::serveMeal()
{
    int i = 1;
    while(!mMeal.empty())
    {
        cout << " Serve item " << i++ << ":" << mMeal.front() << endl ;
        mMeal.pop();
    }
}
