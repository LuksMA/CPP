
### Comments:
1. Use **structures** to store different types of data.
2. '**static**' is used to make access to any data variable or function without making an object of that class. It means that 'static' is used so that we can access any data variable or function without making an object of that class.
3. Need for Initialization List :
If we declare any variable as **const**, then that variable can be initialized, but not assigned.
4. Any **protected** member of a class ( variable or function ) can be accessed within that class or its subclass. It cannot be accessed outside that.
5. For **subclass**, while calling the constructor of any class, the compiler first automatically calls the constructor of its parent class. 
6. Conditions for Function Overriding
* Functions of both parent and child class must have the same name.
* Functions must have the same argument list and return type.
* A function declared static cannot be overridden.
* If a function cannot be inherited, it cannot be overridden.
* Constructors cannot be overridden.
7. Binding means matching the function call with the correct function definition by the compiler. It takes place either at compile time or at runtime
* In early binding, the compiler matches the function call with the correct function definition at compile time. It is also known as **Static Binding** or **Compile-time Binding**.
* **Virtual Function** is a member function of the base class which is overridden in the derived class. The compiler performs **late binding** on this function
* If we declare a member function in a base class as a virtual function, then that function automatically becomes virtual in all of its derived classes.
* We can also call private function of derived class from a base class pointer by declaring that function in the base class as virtual.
