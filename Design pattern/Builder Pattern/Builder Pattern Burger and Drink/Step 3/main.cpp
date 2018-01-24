#include <iostream>

#include "MealBuilder.h"
#include "Meal.h"

using namespace std;

int main(){
    MealBuilder mealBuilder;
    Meal* vegMeal = mealBuilder.prepareVegMeal();
    cout<<"Veg Meal:"<<endl;
    vegMeal->showItems();
    cout<<"Total Cost: "<<vegMeal->getCost()<<endl;

    Meal* nonVegMeal = mealBuilder.prepareNonVegMeal();
    cout<<"Non-Veg Meal:"<<endl;
    nonVegMeal->showItems();
    cout<<"Total Cost: "<<nonVegMeal->getCost()<<endl;
}

//Veg Meal:
//Item : Veg Burger, Packing : Wrapper, Price : 25
//Item : Coke, Packing : Bottle, Price : 30
//Total Cost: 55
//Non-Veg Meal:
//Item : Chicken  Burger, Packing : Wrapper, Price : 50
//Item : Pepsi, Packing : Bottle, Price : 35
//Total Cost: 85
