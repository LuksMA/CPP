### Definition
单例模式(Singleton Pattern)：单例模式确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例，这个类称为单例类，它提供全局访问的方法。

单例模式的要点有三个：一是某个类只能有一个实例；二是它必须自行创建这个实例；三是它必须自行向整个系统提供这个实例。单例模式是一种对象创建型模式。单例模式又名单件模式或单态模式。

1. Define a private static attribute in the "single instance" class
2. Define a public static accessor function in the class
3. Do "lazy initialization" (creation on demand) in the accessor function
4. Define all constructors to be protected or private
5. Clients may only use the accessor function to manipulate the Singleton
6. Inheritance can be supported, but static functions may not be overridden. The base class must be declared a friend of the derived class (in order to access the protected constructor).

### UML
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Singleton%20Pattern/image/Singleton.jpg)

### Sequence diagram
![alt text](https://github.com/vectormars/CPP/blob/master/Design%20pattern/Singleton%20Pattern/image/seq_Singleton.jpg)
