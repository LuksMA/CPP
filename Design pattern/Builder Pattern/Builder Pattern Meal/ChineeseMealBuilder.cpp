#include "ChineeseMealBuilder.h"

ChineeseMealBuilder::ChineeseMealBuilder()
{
    //ctor
}

ChineeseMealBuilder::~ChineeseMealBuilder()
{
    //dtor
}
void ChineeseMealBuilder::buildStarter()
{
    mMeal.setMealItem("Manchurian");
}
void ChineeseMealBuilder::buildMainCourse()
{
    mMeal.setMealItem("FriedNoodles");
}
void ChineeseMealBuilder::buildDessert()
{
    mMeal.setMealItem("MangoPudding");
}
