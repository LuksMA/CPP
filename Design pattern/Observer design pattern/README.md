### Intend
建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，其他对象将相应做出反应。在此，发生改变的对象称为观察目标，而被通知的对象称为观察者，一个观察目标可以对应多个观察者，而且这些观察者之间没有相互联系，可以根据需要增加和删除观察者，使得系统更易于扩展，这就是观察者模式的模式动机。

### Definition
The observer pattern defines a one-to-many dependency between objects so that when one object changes state, all of its dependents are notified and updated automatically.       
Also, called 发布-订阅（Publish/Subscribe）模式、模型-视图（Model/View）模式、源-监听器（Source/Listener）模式或从属者（Dependents）模式。

The object which is being watched is called the **subject**. The objects which are watching the state changes are called observers or listeners.

Observer pattern uses three actor classes. **Subject**, **Observer** and **Events**. 
* Subject (目标): accepts registration requests according to some key or event. Notifies observers reigstered for a given event.
* ConcreteSubject: 具体目标
* Observers (观察者): register themselves to be notified by the observer for a given eventSubject
* ConcreteObserver: 具体观察者
* Events: Act as registration key and trigger for notification

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Observer%20design%20pattern/image/Obeserver.jpg)

### Sequence Diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Observer%20design%20pattern/image/seq_Obeserver.jpg)

### Class inheritance vs type inheritance
* Class inheritance defines an object's implementation in terms of another object's implementation.    
* Type inheritance describes when an object can be used in place of another.

### Real world example
1. When you subscribe to any website.   
You are on observer in this case who has subscribed to a website (Subject) for getting notified about its post.    
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Observer%20design%20pattern/image/Observer%20Design%20Pattern.jpg)
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Observer%20design%20pattern/image/ObserverDesignPattern.jpg)
2. Follow feature on Quora.       
As I can see right now, there are 18 followers of this question. As soon as I click on Submit after writing my answer, Quora (Subject) will send a notification to all 18 followers (observers).

3. Cricket Display     
The scoreboard display, displays the average score etc information as per the current status of the match. Whenever any score changes, the scoreboard gets refreshed. So, display board is the observer here and Subject is the panel sending the current score status to the board.

4. Whatsapp Group      
Whenever any person sends any message in the group, all the people who are in the group get notified.

https://sourcemaking.com/design_patterns/observer/cpp/1              
https://sourcemaking.com/design_patterns/observer/cpp/2     
https://sourcemaking.com/design_patterns/observer/cpp/3     
http://design-patterns.readthedocs.io/zh_CN/latest/behavioral_patterns/observer.html
