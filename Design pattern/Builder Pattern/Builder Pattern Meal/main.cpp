#include <iostream>

#include "MultiCuisineCook.h"
#include "ChineeseMealBuilder.h"
#include "IndianMealBuilder.h"
#include "MexicanMealBuilder.h"

using namespace std;

int main()
{
    MultiCuisineCook cook;

    cout << "Build a Chineese Meal!" << endl;
    cook.setMealBuilder(new ChineeseMealBuilder());
    cook.createMeal();

    Meal chineeseMeal = cook.getMeal();
    chineeseMeal.serveMeal();

    cout << "Build a Mexican Meal!" << endl;
    cook.setMealBuilder(new MexicanMealBuilder());
    cook.createMeal();

    Meal mexicanMeal = cook.getMeal();
    mexicanMeal.serveMeal();

    return 0;
}


//Build a Chineese Meal!
// Serve item 1:Manchurian
// Serve item 2:FriedNoodles
// Serve item 3:MangoPudding
//Build a Mexican Meal!
// Serve item 1:ChipsNSalsa
// Serve item 2:RiceTacoBeans
// Serve item 3:FriedIcecream
