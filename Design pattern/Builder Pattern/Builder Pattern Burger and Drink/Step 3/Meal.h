#ifndef MEAL_H
#define MEAL_H

#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Meal{
private:
    vector<Item*> items;

public:
    Meal();
    ~Meal();

    void addItem(Item* item);
    float getCost();
    void showItems();

};

#endif // MEAL_H
