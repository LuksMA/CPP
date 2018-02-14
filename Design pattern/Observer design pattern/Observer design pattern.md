### Definition
The observer pattern defines a one-to-many dependency between objects so that when one object changes state, all of its dependents are notified and updated automatically.

The object which is being watched is called the **subject**. The objects which are watching the state changes are called observers or listeners.

Observer pattern uses three actor classes. **Subject**, **Observer** and **Events**. 
* Subject: accepts registration requests according to some key or event. Notifies observers reigstered for a given event.
* Observers: register themselves to be notified by the observer for a given eventSubject
* Events: Act as registration key and trigger for notification

### Class inheritance vs type inheritance
* Class inheritance defines an object's implementation in terms of another object's implementation.    
* Type inheritance describes when an object can be used in place of another.


https://sourcemaking.com/design_patterns/observer/cpp/1              
https://sourcemaking.com/design_patterns/observer/cpp/2     
https://sourcemaking.com/design_patterns/observer/cpp/3     
