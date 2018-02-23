### Intent
考虑一个简单的软件应用场景，一个软件系统可以提供多个外观不同的按钮（如圆形按钮、矩形按钮、菱形按钮等）， 这些按钮都源自同一个基类，不过在继承基类后不同的子类修改了部分属性从而使得它们可以呈现不同的外观，如果我们希望在使用这些按钮时，不需要知道这些具体按钮类的名字，只需要知道表示该按钮类的一个参数，并提供一个调用方便的方法，把该参数传入方法即可返回一个相应的按钮对象，此时，就可以使用简单工厂模式。

### Definition
Factory Pattern (**Static Factory Method**) is "A factory is an object for creating other objects". Simple Factory Pattern is a Factory class in its simplest form (In comparison to Factory Method Pattern or Abstract Factory Pattern). In another way, we can say: In simple factory pattern, we have a factory class which has a method that returns different types of object based on given input.

There are three variations of the factory pattern:
1. **Simple Factory Pattern**. This allows interfaces for creating objects without exposing the object creation logic to the client.
2. **Factory Method Pattern**. This allows interfaces for creating objects, but allow subclasses to determine which class to instantiate.
3. **Abstract Factory Pattern**. Unlike the above two patterns, an abstract factory is an interface to create of related objects without specifying/exposing their classes. We can also say that it provides an object of another factory that is responsible for creating required objects.

### Structure
* **Factory：工厂角色**
工厂角色负责实现创建所有实例的内部逻辑
* **Product：抽象产品角色**
抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口
* **ConcreteProduct：具体产品角色**
具体产品角色是创建目标，所有创建的对象都充当这个角色的某个具体类的实例。

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Simple%20Factory%20Pattern/image/SimpleFactory.jpg)
### Sequence diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Simple%20Factory%20Pattern/image/seq_SimpleFactory.jpg)

https://code.tutsplus.com/tutorials/design-patterns-the-simple-factory-pattern--cms-22345   
https://www.codeproject.com/Articles/1131770/Factory-Patterns-Simple-Factory-Pattern    
http://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/simple_factory.html    
