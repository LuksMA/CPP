#include "Meal.h"

Meal::Meal(){
    //ctor
}

Meal::~Meal(){
    //dtor
}

void Meal::addItem(Item* item){
    items.push_back(item);
}

float Meal::getCost(){
    float cost = 0.0f;

    for (auto item : items){
        cost += item->price();
    }
    return cost;
}

void Meal::showItems(){
    for (auto item : items){
        cout<<"Item : "<<item->name();
        cout<<", Packing : "<<item->packing()->pack();
        cout<<", Price : "<<item->price();
        cout<<endl;
    }
}
