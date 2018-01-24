#include "IndianMealBuilder.h"

IndianMealBuilder::IndianMealBuilder()
{
    //ctor
}

IndianMealBuilder::~IndianMealBuilder()
{
    //dtor
}


void IndianMealBuilder::buildStarter()
{
    mMeal.setMealItem("FriedOnion");
}
void IndianMealBuilder::buildMainCourse()
{
    mMeal.setMealItem("CheeseCurry");
}
void IndianMealBuilder::buildDessert()
{
    mMeal.setMealItem("SweetBalls");
}
