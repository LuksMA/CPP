### Intent
* Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.
* Design an intermediary to decouple many peers.
* Promote the many-to-many relationships between interacting peers to "full object status".

#### Previous
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Mediator%20Pattern/image/Mediator.svg)     
If we were to model this in software, we could decide to have User objects coupled to Group objects, and Group objects coupled to User objects. Then when changes occur, both classes and all their instances would be affected.

#### After
An alternate approach would be to introduce "an additional level of indirection" - take the mapping of users to groups and groups to users, and make it an abstraction unto itself. This offers several advantages: Users and Groups are decoupled from one another, many mappings can easily be maintained and manipulated simultaneously, and the mapping abstraction can be extended in the future by defining derived classes.     
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Mediator%20Pattern/image/Mediator_1.svg)    
Partitioning a system into many objects generally enhances reusability, but proliferating interconnections between those objects tend to reduce it again. The mediator object: encapsulates all interconnections, acts as the hub of communication, is responsible for controlling and coordinating the interactions of its clients, and promotes loose coupling by keeping objects from referring to each other explicitly.

The Mediator pattern promotes a "many-to-many relationship network" to "**full object status**". Modelling the inter-relationships with an object enhances encapsulation, and allows the behavior of those inter-relationships to be modified or extended through subclassing.

* **Mediator**: 抽象中介者
* **ConcreteMediator**: 具体中介者
* **Colleague**: 抽象同事类
* **ConcreteColleague**: 具体同事类

### Class Diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Mediator%20Pattern/image/Mediator.jpg)
### Sequence Diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Mediator%20Pattern/image/seq_Mediator.jpg)
### Real world example
#### Eg1:
An example where Mediator is useful is the design of a user and group capability in an operating system. A group can have zero or more users, and, a user can be a member of zero or more groups. The Mediator pattern provides a flexible and non-invasive way to associate and manage users and groups.

#### Eg2: 虚拟聊天室
某论坛系统欲增加一个虚拟聊天室，允许论坛会员通过该聊天室进行信息交流，普通会员(CommonMember)可以给其他会员发送文本信息，钻石会员(DiamondMember)既可以给其他会员发送文本信息，还可以发送图片信息。该聊天室可以对不雅字符进行过滤，如“日”等字符；还可以对发送的图片大小进行控制。用中介者模式设计该虚拟聊天室。

### Suggestion
* 系统中对象之间存在复杂的引用关系，产生的相互依赖关系结构混乱且难以理解。
* 一个对象由于引用了其他很多对象并且直接和这些对象通信，导致难以复用该对象。
* 想通过一个中间类来封装多个类中的行为，而又不想生成太多的子类。可以通过引入中介者类来实现，在中介者中定义对象。
* 交互的公共行为，如果需要改变行为则可以增加新的中介者类。
* 中介者模式适用情况包括：系统中对象之间存在复杂的引用关系，产生的相互依赖关系结构混乱且难以理解；一个对象由于引用了其他很多对象并且直接和这些对象通信，导致难以复用该对象；想通过一个中间类来封装多个类中的行为，而又不想生成太多的子类
* 中介者模式与GUI开发
  * 中介者模式可以方便地应用于图形界面(GUI)开发中，在比较复杂的界面中可能存在多个界面组件之间的交互关系。
  * 对于这些复杂的交互关系，有时候我们可以引入一个中介者类，将这些交互的组件作为具体的同事类，将它们之间的引用和控制关系交由中介者负责，在一定程度上简化系统的交互，这也是中介者模式的常见应用之一。


https://sourcemaking.com/design_patterns/mediator    
https://sourcemaking.com/design_patterns/mediator/cpp/1    
https://sourcemaking.com/design_patterns/mediator/cpp/2     
http://design-patterns.readthedocs.io/zh_CN/latest/behavioral_patterns/mediator.html
