![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML/image/uml_class_struct.jpg)

### Class relationship
* Association (knows a)
* Dependency (uses a)
* Composition (has a)
* Aggregation (has a)
* Inheritance (is a)
* Class template

#### Association (knows a)
One object is aware of another; it contains a pointer or reference to another object.    
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML/image/uml_association.jpg)     
```cpp
Class X {
  X(Y *y) : y_ptr(y) {}
  void SetY(Y *y) { y_ptr = y;   }
  void f()        { y_ptr->Foo();}
  ----
  Y *y_ptr; // pointer
};
```

#### Dependency (uses a)
One object issues a function call to a member function of another object. That means one class depends on another if the independent class is a parameter variable or local variable of a method of the dependent class  
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML/image/uml_dependency.jpg)    
```cpp
class X {
 ...
 void f1(Y y)  {…;  y.Foo();       }
 void f2(Y *y) {…;  y->Foo();      }
 void f3(Y &y) {…;  y.Foo();       }
 void f4()     {   Y y; y.Foo();  …}
 void f5()     {…; Y::StaticFoo(); }
 ...
};
```

#### Inheritance (is a) 
A class is derived from another class    
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML/image/uml_generalization.jpg)

#### Composition or Aggregation (has a)
* Both are “Has a” or “part-of” relationship
* Composition
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML/image/uml_composition.jpg)
  * A stronger variety of aggregation
  * The part object may belong to only one
whole
  * Expected to live and die with the whole
    * delete whole also delete part
```cpp
class X {
...
Y a; // 1; Composition
Y b[10]; // 0..10; Composition
};
 
class X {
X() { a = new Y[10]; }
~X(){ delete [] a; }
...
Y *a; // 0..10; Composition
};
 
class X {
...
vector a;
};
```
* Aggregation
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/UML/image/uml_aggregation.jpg)
  * Cascading delete is often
  * An aggregated instance can be shared
 ```cpp
class Window
{
 public:
  //...
 private:
 vector<Shape*> itsShapes;
};
```
 
#### Class Template
Template class mean generic classes
