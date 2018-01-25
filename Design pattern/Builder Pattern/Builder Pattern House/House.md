Based on https://www.geeksforgeeks.org/builder-design-pattern/
1. Create interface **HousePlan**    
2. Create concrete class **House** inplement the interface **HousePlan**       
3. Create abstract class **HouseBuilder** using the object **House**    
4. Create concrete class **IglooHouseBuilder** and **TipiHouseBuilder** that extend **HouseBuilder**    
5. Create concrete class **CivilEngineer** (Director) builing types of **House**   

##### Summary:
1. Build **object** class   
2. Based on the **object** class, create abstract class **builder**  
3. Using abstract class **builder**, create types of builders, concrete classes that extend **builder**        
4. Create **direct** that implement **builder**, building types of **objetcs**    
