![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Design%20Patterns.jpg)
### Creational patterns
创建型模式(Creational Pattern)对类的实例化过程进行了抽象，能够将软件模块中对象的创建和对象的使用分离。为了使软件的结构更加清晰，外界对于这些对象只需要知道它们共同的接口，而不清楚其具体的实现细节，使整个系统的设计更加符合单一职责原则。

创建型模式在创建什么(What)，由谁创建(Who)，何时创建(When)等方面都为软件设计者提供了尽可能大的灵活性。创建型模式隐藏了类的实例的创建细节，通过隐藏对象如何被创建和组合在一起达到使整个系统独立的目的。

* [Abstract Factory](https://github.com/vectormars/CPP/tree/master/Design%20pattern/Abstract%20Factory%20Pattern)     
Creates an instance of several families of classes
* Builder    
Separates object construction from its representation
* Factory Method    
Creates an instance of several derived classes
* Object Pool    
Avoid expensive acquisition and release of resources by recycling objects that are no longer in use
* Prototype    
A fully initialized instance to be copied or cloned
* Singleton    
A class of which only a single instance can exist

#### More about factory pattern
There are three variations of the factory pattern:
1. **Simple Factory Pattern**. This allows interfaces for creating objects without exposing the object creation logic to the client.
2. **Factory Method Pattern**. This allows interfaces for creating objects, but allow subclasses to determine which class to instantiate.
3. **Abstract Factory Pattern**. Unlike the above two patterns, an abstract factory is an interface to create of related objects without specifying/exposing their classes. We can also say that it provides an object of another factory that is responsible for creating required objects.

### Structural patterns
结构型模式(Structural Pattern)描述如何将类或者对 象结合在一起形成更大的结构，就像搭积木，可以通过 简单积木的组合形成复杂的、功能更为强大的结构。

* Adapter   
Match interfaces of different classes
* Bridge   
Separates an object's interface from its implementation
* Composite   
A tree structure of simple and composite objects
* Decorator   
Add responsibilities to objects dynamically
* Facade    
A single class that represents an entire subsystem
* Flyweight    
A fine-grained instance used for efficient sharing
* Private Class Data    
Restricts accessor/mutator access
* Proxy    
An object representing another object

### Behavioral patterns
行为型模式(Behavioral Pattern)是对在不同的对象之间划分责任和算法的抽象化。

行为型模式不仅仅关注类和对象的结构，而且重点关注它们之间的相互作用。

通过行为型模式，可以更加清晰地划分类与对象的职责，并研究系统在运行时实例对象 之间的交互。在系统运行时，对象并不是孤立的，它们可以通过相互通信与协作完成某些复杂功能，一个对象在运行时也将影响到其他对象的运行.

* Chain of responsibility    
A way of passing a request between a chain of objects
* Command    
Encapsulate a command request as an object
* Interpreter    
A way to include language elements in a program
* Iterator   
Sequentially access the elements of a collection
* Mediator    
Defines simplified communication between classes
* Memento    
Capture and restore an object's internal state
* Null Object    
Designed to act as a default value of an object
* Observer    
A way of notifying change to a number of classes
* State    
Alter an object's behavior when its state changes
* Strategy    
Encapsulates an algorithm inside a class
* Template method    
Defer the exact steps of an algorithm to a subclass
* Visitor    
Defines a new operation to a class without change


https://sourcemaking.com/design_patterns/behavioral_patterns     
http://design-patterns.readthedocs.io/zh_CN/latest/index.html