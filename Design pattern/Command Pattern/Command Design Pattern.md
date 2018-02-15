### Intend:
在软件设计中，我们经常需要向某些对象发送请求，但是并不知道请求的接收者是谁，也不知道被请求的操作是哪个，我们只需在程序运行时指定具体的请求接收者即可，此时，可以使用命令模式来进行设计，使得请求发送者与请求接收者消除彼此之间的耦合，让对象之间的调用关系更加灵活

* **Command**: This is an interface for executing an action.
* **ConcreteCommand**: This object specifies the binding between a Receiver/action taker and an action invoker. This object is responsible for executing the corresponding operation on the Receiver.
* **Client**: Creates a ConcreteCommand object and sets its receiver.
* **Invoker**: It will use the Command object to carry out the request.
* **Receiver**: It contains the real operational logic that needs to be performed on the data.

### Advantages:

* Makes our code extensible as we can add new commands without changing existing code.
* Reduces coupling the invoker and receiver of a command.
### Disadvantages:

* Increase in the number of classes for each individual command


https://sourcemaking.com/design_patterns/command/cpp/1    
https://sourcemaking.com/design_patterns/command/cpp/2    
https://sourcemaking.com/design_patterns/command/cpp/3    
https://www.geeksforgeeks.org/command-pattern/   
