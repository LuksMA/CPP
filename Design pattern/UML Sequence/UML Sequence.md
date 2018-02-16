### Definition:
Sequence diagrams are a popular dynamic modeling solution in UML because they specifically focus on lifelines, or the processes and objects that live simultaneously, and the messages exchanged between them to perform a function before the lifeline ends.

### Basic Sequence Diagram Notations
* **Class Roles or Participants**    
Class roles describe the way an object will behave in context. Use the UML object symbol to illustrate class roles, but don't list object attributes.      
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/component.jpg)
* **Activation or Execution Occurrence**     
Activation boxes represent the time an object needs to complete a task. When an object is busy executing a process or waiting for a reply message, use a thin gray rectangle placed vertically on its lifeline.
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/activation-or-execution.jpg)
* **Messages**      
Messages are arrows that represent communication between objects. Use half-arrowed lines to represent asynchronous messages. Asynchronous messages are sent from an object that will not wait for a response from the receiver before continuing its tasks.             
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/messages.jpg)
* **Lifelines**     
Lifelines are vertical dashed lines that indicate the object's presence over time.   
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/lifeline.jpg)
* **Destroying Objects**     
Objects can be terminated early using an arrow labeled "<< destroy >>" that points to an X. This object is removed from memory. When that object's lifeline ends, you can place an X at the end of its lifeline to denote a destruction occurrence.
* **Loops**    
A repetition or loop within a sequence diagram is depicted as a rectangle. Place the condition for exiting the loop at the bottom left corner in square brackets [ ].

### Types of Messages in Sequence Diagrams
* **Synchronous Message**     
A synchronous message requires a response before the interaction can continue. It's usually drawn using a line with a solid arrowhead pointing from one object to another.   
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/synchronous-message.jpg)
* **Asynchronous Message**    
Asynchronous messages don't need a reply for interaction to continue. Like synchronous messages, they are drawn with an arrow connecting two lifelines; however, the arrowhead is usually open and there's no return message depicted.     
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/simple-message.jpg)      
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/asynchronous-message.jpg)
* **Reply or Return Message**
A reply message is drawn with a dotted line and an open arrowhead pointing back to the original lifeline.    
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/reply-or-return-message.jpg)   
* **Self Message**       
A message an object sends to itself, usually shown as a U shaped arrow pointing back to itself.
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/self-message.jpg)
* **Create Message**    
This is a message that creates a new object. Similar to a return message, it's depicted with a dashed line and an open arrowhead that points to the rectangle representing the object created.     
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/create-message.jpg)
* **Delete Message**    
This is a message that destroys an object. It can be shown by an arrow with an x at the end.     
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/delete-message.jpg)
* **Found Message**   
A message sent from an unknown recipient, shown by an arrow from an endpoint to a lifeline.     
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/found-message.gif)
* **Lost Message**
A message sent to an unknown recipient. It's shown by an arrow going from a lifeline to an endpoint, a filled circle or an x      
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML%20Sequence/image/lost-message.gif)





https://www.lucidchart.com/pages/uml-sequence-diagram     
https://www.smartdraw.com/sequence-diagram/
