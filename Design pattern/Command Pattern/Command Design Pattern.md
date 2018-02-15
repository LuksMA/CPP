### Intend:
在软件设计中，我们经常需要向某些对象发送请求，但是并不知道请求的接收者是谁，也不知道被请求的操作是哪个，我们只需在程序运行时指定具体的请求接收者即可，此时，可以使用命令模式来进行设计，使得请求发送者与请求接收者消除彼此之间的耦合，让对象之间的调用关系更加灵活

* **Command**: 抽象命令类     
This is an interface for executing an action.
* **ConcreteCommand**: 具体命令类   
This object specifies the binding between a Receiver/action taker and an action invoker. This object is responsible for executing the corresponding operation on the Receiver.
* **Client**: 客户类   
Creates a ConcreteCommand object and sets its receiver.
* **Invoker**: 调用者   
It will use the Command object to carry out the request.
* **Receiver**: 接收者   
It contains the real operational logic that needs to be performed on the data.

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Command%20Pattern/Command.jpg)
### Sequence Diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Command%20Pattern/seq_Command.jpg)

### Advantages:
* 可以比较容易地设计一个命令队列和宏命令（组合命令）。
* 可以方便地实现对请求的Undo和Redo。
* Makes our code extensible as we can add new commands without changing existing code. 新的命令可以很容易地加入到系统中。
* Reduces coupling the invoker and receiver of a command. 降低系统的耦合度。

### Disadvantages:
* Increase in the number of classes for each individual command. 使用命令模式可能会导致某些系统有过多的具体命令类。因为针对每一个命令都需要设计一个具体命令类，因此某些系统可能需要大量具体命令类，这将影响命令模式的使用。

### Suggestion
* 系统需要将请求调用者和请求接收者解耦，使得调用者和接收者不直接交互。
* 系统需要在不同的时间指定请求、将请求排队和执行请求。
* 系统需要支持命令的撤销(Undo)操作和恢复(Redo)操作。
* 系统需要将一组操作组合在一起，即支持宏命令

### Real world example (TV remote)
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Command%20Pattern/Command_eg.jpg)

![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Command%20Pattern/seq_Command_eg.jpg)

https://sourcemaking.com/design_patterns/command/cpp/1    
https://sourcemaking.com/design_patterns/command/cpp/2    
https://sourcemaking.com/design_patterns/command/cpp/3    
https://www.geeksforgeeks.org/command-pattern/   
http://design-patterns.readthedocs.io/zh_CN/latest/behavioral_patterns/command.html#id26     
