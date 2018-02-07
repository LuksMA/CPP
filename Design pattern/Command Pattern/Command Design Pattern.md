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
