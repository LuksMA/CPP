### Intent
设想如果要绘制矩形、圆形、椭圆、正方形，我们至少需要4个形状类，但是如果绘制的图形需要具有不同的颜色，如红色、绿色、蓝色等，此时至少有如下两种设计方案：

* 第一种设计方案是为每一种形状都提供一套各种颜色的版本。
* 第二种设计方案是根据实际需要对形状和颜色进行组合
对于有两个变化维度（即两个变化的原因）的系统，采用方案二来进行设计系统中类的个数更少，且系统扩展更为方便。设计方案二即是桥接模式的应用。桥接模式将继承关系转换为关联关系，从而降低了类与类之间的耦合，减少了代码编写量.

### Definition
桥接模式(Bridge Pattern)：将抽象部分与它的实现部分分离，使它们都可以独立地变化。它是一种对象结构型模式，又称为柄体(Handle and Body)模式或接口(Interface)模式。

### Structure
* Abstraction：抽象类
* RefinedAbstraction：扩充抽象类
* Implementor：实现类接口
* ConcreteImplementor：具体实现类

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Bridge%20Pattern/image/Bridge.jpg)
### Sequence diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Bridge%20Pattern/image/seq_Bridge.jpg)

### Advantage
* 分离抽象接口及其实现部分。
* 桥接模式有时类似于多继承方案，但是多继承方案违背了类的单一职责原则（即一个类只有一个变化的原因），复用性比较差，而且多继承结构中类的个数非常庞大，桥接模式是比多继承方案更好的解决方法。
* 桥接模式提高了系统的可扩充性，在两个变化维度中任意扩展一个维度，都不需要修改原有系统。
* 实现细节对客户透明，可以对用户隐藏实现细节。

### Disadvantage
桥接模式的引入会增加系统的理解与设计难度，由于聚合关联关系建立在抽象层，要求开发者针对抽象进
行设计与编程。 

桥接模式要求正确识别出系统中两个独立变化的维度，因此其使用范围具有一定的局限性