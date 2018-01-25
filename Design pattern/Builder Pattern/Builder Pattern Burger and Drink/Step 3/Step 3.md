1.1 Create **Packing** Interface (virtual pack())    
1.2 Create concrete class (**Wrapper** and **Bottle**) implementing the **Packing** interface. (Two Types of packing)    
2.1 Create an interface **Item** representing food item, including virtual name(), virtual packing(), virtual price().    
2.2 Create abstract classes (**Burger** and **ColdDrink**) implementing the **Item** interface providing default functionalities, packing(), virtual price().   
3. Create concrete classes (**VegBurger**,**ChickenBurger**,**Coke**,**Pepsi**) extending abstract classes (**Burger** and **ColdDrink**)  
4. Create concrete classes **meal** having the defined **Item** objects, vector<**Item***>, addItem(), getCost(), showItems()    
5. Create concrete classes **MealBuilder**, the actual builder class responsible to create Meal objects.

based on https://www.tutorialspoint.com/design_pattern/builder_pattern.htm


**Item**: name, packing, price    
**Item** 
==> Burger ==> VegBurger & ChickenBurger        
==> ColdDrink ==> Coke & Pepsi   
Create **Meal** objects by **MealBuilder**:     
VegMeal(VegBurger + Coke), NonVegMeal(ChickenBurger + Pepsi)

