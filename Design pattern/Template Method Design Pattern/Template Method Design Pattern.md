### Definition: 
The Template pattern is used in scenarios where we want to create **extendable** behaviors in generalization and specialization relationships.

* Define the skeleton of an algorithm in an operation, deferring some steps to client subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.
* Base class declares algorithm 'placeholders', and derived classes implement the placeholders.

### Rules of thumb
* Strategy is like Template Method except in its granularity.
* Template Method uses inheritance to vary part of an algorithm. Strategy uses delegation to vary the entire algorithm.
* Strategy modifies the logic of individual objects. Template Method modifies the logic of an entire class.
* Factory Method is a specialization of Template Method

https://sourcemaking.com/design_patterns/template_method
https://sourcemaking.com/design_patterns/template_method/cpp/1
https://sourcemaking.com/design_patterns/template_method/cpp/2     
https://www.codeproject.com/Articles/307452/common-use-of-Template-Design-pattern-Design-pat
