#include "MexicanMealBuilder.h"

MexicanMealBuilder::MexicanMealBuilder()
{
    //ctor
}

MexicanMealBuilder::~MexicanMealBuilder()
{
    //dtor
}

void MexicanMealBuilder::buildStarter()
{
    mMeal.setMealItem("ChipsNSalsa");
}
void MexicanMealBuilder::buildMainCourse()
{
    mMeal.setMealItem("RiceTacoBeans");
}
void MexicanMealBuilder::buildDessert()
{
    mMeal.setMealItem("FriedIcecream");
}
