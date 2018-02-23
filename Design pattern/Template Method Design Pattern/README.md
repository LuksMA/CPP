### Definition: 
The Template pattern is used in scenarios where we want to create **extendable** behaviors in generalization and specialization relationships.

* Define the skeleton of an algorithm in an operation, deferring some steps to client subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.
* Base class declares algorithm 'placeholders', and derived classes implement the placeholders.

![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Template%20Method%20Design%20Pattern/template_method.jpg)

### Rules of thumb
* Strategy is like Template Method except in its granularity.
* Template Method uses inheritance to vary part of an algorithm. Strategy uses delegation to vary the entire algorithm.
* Strategy modifies the logic of individual objects. Template Method modifies the logic of an entire class.
* Factory Method is a specialization of Template Method

### Real world example
* Scenario 1: Flexible extendable generalized specialized user interfaces
  * InitializeComponent: This will create the UI objects needed for the form.
  * LoadCustomer: This function will load data and bind to the grid.
  * LoadGrid: This function will define the look and feel of the grid.
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Template%20Method%20Design%20Pattern/S1.JPG)

* Scenario 2: ASP.NET page life cycle        
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Template%20Method%20Design%20Pattern/S2.JPG)

* Scenario 3: Code generators         
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Template%20Method%20Design%20Pattern/S3.JPG)

* Scenario 4: XML parser
* Scenario 5: Validation in business components
* Scenario 6: Customizable logging utility         
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Template%20Method%20Design%20Pattern/S6.JPG)


https://sourcemaking.com/design_patterns/template_method
https://sourcemaking.com/design_patterns/template_method/cpp/1
https://sourcemaking.com/design_patterns/template_method/cpp/2     
https://www.codeproject.com/Articles/307452/common-use-of-Template-Design-pattern-Design-pat
