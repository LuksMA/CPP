In computer programming, the strategy pattern (also known as the policy pattern) is a software design pattern that enables an algorithm's **behavior** to be selected at **runtime**.

* Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary **independently from the clients that use it**.
* Capture the abstraction in an interface, bury implementation details in derived classes.

![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Strategy%20Design%20Pattern/image/DP-Strategy-Structure.png)

* Context: 环境类
* Strategy: 抽象策略类
* ConcreteStrategy: 具体策略类

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Strategy%20Design%20Pattern/image/Strategy.jpg)
### Sequence Diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Strategy%20Design%20Pattern/image/seq_Strategy.jpg)

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

### Summary
* 在策略模式中定义了一系列算法，将每一个算法封装起来，并让它们可以相互替换。策略模式让算法独立于使用它的客户而变化，也称为政策模式。策略模式是一种对象行为型模式。
* 策略模式包含三个角色：环境类在解决某个问题时可以采用多种策略，在环境类中维护一个对抽象策略类的引用实例；抽象策略类为所支持的算法声明了抽象方法，是所有策略类的父类；具体策略类实现了在抽象策略类中定义的算法。
* 策略模式是对算法的封装，它把算法的责任和算法本身分割开，委派给不同的对象管理。策略模式通常把一个系列的算法封装到一系列的策略类里面，作为一个抽象策略类的子类。
* 策略模式主要优点在于对“开闭原则”的完美支持，在不修改原有系统的基础上可以更换算法或者增加新的算法，它很好地管理算法族，提高了代码的复用性，是一种替换继承，避免多重条件转移语句的实现方式；其缺点在于客户端必须知道所有的策略类，并理解其区别，同时在一定程度上增加了系统中类的个数，可能会存在很多策略类。
* 策略模式适用情况包括：在一个系统里面有许多类，它们之间的区别仅在于它们的行为，使用策略模式可以动态地让一个对象在许多行为中选择一种行为；一个系统需要动态地在几种算法中选择一种；避免使用难以维护的多重条件选择语句；希望在具体策略类中封装算法和与相关的数据结构

https://sourcemaking.com/design_patterns/strategy    
https://sourcemaking.com/design_patterns/strategy/cpp/1    
https://www.geeksforgeeks.org/strategy-pattern-set-1/   
https://www.geeksforgeeks.org/strategy-pattern-set-2/   
https://r3dux.org/2011/07/an-example-implementation-of-the-strategy-design-pattern-in-c/    
https://www.codeproject.com/Articles/889/Applying-Strategy-Pattern-in-C-Applications    
http://thispointer.com/strategy-design-pattern/   
