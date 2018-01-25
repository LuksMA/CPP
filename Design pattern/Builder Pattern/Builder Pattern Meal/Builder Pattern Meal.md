Based on   
http://www.sourcetricks.com/2013/04/builder-pattern.html#.Wmi2P66nGpo

1. Create an interface "Meal.h" representing product.  
2. Create concrete classes "Meal.cpp" implementing the "Meal.h" interface.
3. Create abstract classes "MealBuilder" implementing the "Meal.h" interface providing default functionalities.   
4. Create concrete classes "MultiCuisineCook" implementing the "MealBuilder.h" interface. Makes sure the right sequence of food is prepared and served.
5. Create concrete classes extending "MealBuilder", such as "IndianMealBuilder", "ChineeseMealBuilder" and "MexicanMealBuilder".


* Product: **Meal** (queue, input info, output info)   
* Builder: **MealBuilder**, include buildStarter(), buildMainCourse(), buildDessert()       
* Director: **MultiCuisineCook**, control the sequence order (implement **MealBuilder**)   
* ConcreteBuilder: IndianMealBuilder, ChineeseMealBuilder and MexicanMealBuilder (extend **MealBuilder**)  


