#include "MealBuilder.h"

MealBuilder::MealBuilder()
{
    //ctor
}

MealBuilder::~MealBuilder()
{
    //dtor
}
Meal* MealBuilder::prepareVegMeal(){
    Meal* meal = new Meal();
    meal->addItem(new VegBurger());
    meal->addItem(new Coke());
    return meal;
}

Meal* MealBuilder::prepareNonVegMeal(){
    Meal* meal = new Meal();
    meal->addItem(new ChickenBurger());
    meal->addItem(new Pepsi());
    return meal;
}
