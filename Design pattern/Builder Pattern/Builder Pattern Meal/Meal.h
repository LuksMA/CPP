#ifndef MEAL_H
#define MEAL_H


#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Meal
{
    private:
        queue <string> mMeal;

    public:
        Meal();
        ~Meal();

        void setMealItem(string mealItem);
        void serveMeal();
};

#endif // MEAL_H
