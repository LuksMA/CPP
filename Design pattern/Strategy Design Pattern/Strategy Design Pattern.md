In computer programming, the strategy pattern (also known as the policy pattern) is a software design pattern that enables an algorithm's behavior to be selected at runtime.

* Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from the clients that use it.
* Capture the abstraction in an interface, bury implementation details in derived classes.

![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Strategy%20Design%20Pattern/DP-Strategy-Structure.png)

### Example
A Strategy defines a set of algorithms that can be used interchangeably. Modes of transportation to an airport is an example of a Strategy. Several options exist such as driving one's own car, taking a taxi, an airport shuttle, a city bus, or a limousine service. For some airports, subways and helicopters are also available as a mode of transportation to the airport. Any of these modes of transportation will get a traveler to the airport, and they can be used interchangeably. The traveler must chose the Strategy based on trade-offs between cost, convenience, and time.

### Rules of thumb
* Strategy is like Template Method except in its granularity.
* State is like Strategy except in its intent.
* Strategy lets you change the guts of an object. Decorator lets you change the skin.
* State, Strategy, Bridge (and to some degree Adapter) have similar solution structures. They all share elements of the 'handle/body' idiom. They differ in intent - that is, they solve different problems.
* Strategy has 2 different implementations, the first is similar to State. The difference is in binding times (Strategy is a bind-once pattern, whereas State is more dynamic).
* Strategy objects often make good Flyweights.

### Advantages
1. A family of algorithms can be defined as a class hierarchy and can be used interchangeably to alter application behavior without changing its architecture.
2. By encapsulating the algorithm separately, new algorithms complying with the same interface can be easily introduced.
3. The application can switch strategies at run-time.
4. Strategy enables the clients to choose the required algorithm, without using a “switch” statement or a series of “if-else” statements.
5. Data structures used for implementing the algorithm are completely encapsulated in Strategy classes. Therefore, the implementation of an algorithm can be changed without affecting the Context class.

### Disadvantages:
1. The application must be aware of all the strategies to select the right one for the right situation.
2. Context and the Strategy classes normally communicate through the interface specified by the abstract Strategy base class. Strategy base class must expose interface for all the required behaviours, which some concrete Strategy classes might not implement.
3. In most cases, the application configures the Context with the required Strategy object. Therefore, the application needs to create and maintain two objects in place of one.

https://sourcemaking.com/design_patterns/strategy    
https://sourcemaking.com/design_patterns/strategy/cpp/1    
https://www.geeksforgeeks.org/strategy-pattern-set-1/   
https://www.geeksforgeeks.org/strategy-pattern-set-2/   
https://r3dux.org/2011/07/an-example-implementation-of-the-strategy-design-pattern-in-c/    
https://www.codeproject.com/Articles/889/Applying-Strategy-Pattern-in-C-Applications    
http://thispointer.com/strategy-design-pattern/   
