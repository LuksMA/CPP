### Intent
现在对该系统进行修改，不再设计一个按钮工厂类来统一负责所有产品的创建，而是将具体按钮的创建过程交给专门的工厂子类去完成，我们先定义一个抽象的按钮工厂类，再定义具体的工厂类来生成圆形按钮、矩形按钮、菱形按钮等，它们实现在抽象按钮工厂类中定义的方法。这种抽象化的结果使这种结构可以在不修改具体工厂类的情况下引进新的产品，如果出现新的按钮类型，只需要为这种新类型的按钮创建一个具体的工厂类就可以获得该新按钮的实例，这一特点无疑使得工厂方法模式具有超越简单工厂模式的优越性，更加符合“开闭原则”。

* Product：抽象产品
* ConcreteProduct：具体产品
* Factory：抽象工厂
* ConcreteFactory：具体工厂

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Factory%20Method%20Pattern/image/FactoryMethod.jpg)
### Sequence diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Factory%20Method%20Pattern/image/seq_FactoryMethod.jpg)

http://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/factory_method.html    
https://sourcemaking.com/design_patterns/factory_method     
https://sourcemaking.com/design_patterns/factory_method/cpp/1   
https://sourcemaking.com/design_patterns/factory_method/cpp/2   
https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/    
https://www.tutorialspoint.com/design_pattern/factory_pattern.htm   
