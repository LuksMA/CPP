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

### Real world example
1. When you subscribe to any website.   
You are on observer in this case who has subscribed to a website (Subject) for getting notified about its post.

2. Follow feature on Quora.       
As I can see right now, there are 18 followers of this question. As soon as I click on Submit after writing my answer, Quora (Subject) will send a notification to all 18 followers (observers).

3. Cricket Display     
The scoreboard display, displays the average score etc information as per the current status of the match. Whenever any score changes, the scoreboard gets refreshed. So, display board is the observer here and Subject is the panel sending the current score status to the board.

4. Whatsapp Group      
Whenever any person sends any message in the group, all the people who are in the group get notified.

https://sourcemaking.com/design_patterns/observer/cpp/1              
https://sourcemaking.com/design_patterns/observer/cpp/2     
https://sourcemaking.com/design_patterns/observer/cpp/3     
