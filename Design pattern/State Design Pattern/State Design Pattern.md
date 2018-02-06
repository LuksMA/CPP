### Intent
* Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.
* An object-oriented state machine
* wrapper + polymorphic wrappee + collaboration

### Discussion
The State pattern is a solution to the problem of how to make behavior depend on state.

* Define a "context" class to present a single interface to the outside world.
* Define a State abstract base class.
* Represent the different "states" of the state machine as derived classes of the State base class.
* Define state-specific behavior in the appropriate State derived classes.
* Maintain a pointer to the current "state" in the "context" class.
* To change the state of the state machine, change the current "state" pointer.

The State pattern does not specify where the state transitions will be defined. The choices are two: the "context" object, or each individual State derived class. The advantage of the latter option is ease of adding new State derived classes. The disadvantage is each State derived class has knowledge of (coupling to) its siblings, which introduces dependencies between subclasses.

A table-driven approach to designing finite state machines does a good job of specifying state transitions, but it is difficult to add actions to accompany the state transitions. The pattern-based approach uses code (instead of data structures) to specify state transitions, but it does a good job of accommodating state transition actions.

### Advantages of State Design Pattern

* With State pattern, the benefits of implementing polymorphic behavior are evident, and it is also easier to add states to support additional behavior.
* In the State design pattern, an object’s behavior is the result of the function of its state, and the behavior gets changed at runtime depending on the state. This removes the dependency on the if/else or switch/case conditional logic. For example, in the TV remote scenario, we could have also implemented the behavior by simply writing one class and method that will ask for a parameter and perform an action (switch the TV on/off) with an if/else block.
* The State design pattern also improves Cohesion since state-specific behaviors are aggregated into the ConcreteState classes, which are placed in one location in the code.

### Disadvantages of State Design Pattern

* The State design pattern can be used when we need to change state of object at runtime by inputting in it different subclasses of some State base class. This circumstance is advantage and disadvantage in the same time, because we have a clear separate State classes with some logic and from the other hand the number of classes grows up.



https://sourcemaking.com/design_patterns/state   
https://www.tutorialspoint.com/design_pattern/state_pattern.htm   
https://www.codeproject.com/Articles/509234/The-State-Design-Pattern-vs-State-Machine   
https://www.geeksforgeeks.org/state-design-pattern/    
http://thispointer.com/state-design-pattern/     
http://gameprogrammingpatterns.com/state.html    
