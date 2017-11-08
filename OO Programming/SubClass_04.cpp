/// While calling the constructor of any class, the compiler first automatically calls the constructor of its parent class.
#include <iostream>

using namespace std;

class A
{
	public:
		A()
		{
			cout << "Constructor of A" << endl;
		}
};

class B : public A
{
	public:
		B()
		{
			cout << "Constructor of B" << endl;
		}
};

class C : public B
{
	public:
		C()
		{
			cout << "Constructor of C" << endl;
		}
};

int main()
{
	cout << "Creating object of A :" << endl;
	A a;
	cout << "Creating object of B :" << endl;
	B b;
	cout << "Creating object of C :" << endl;
	C c;
	return 0;
}


//Output:
//Creating object of A :
//Constructor of A
//Creating object of B :
//Constructor of A
//Constructor of B
//Creating object of C :
//Constructor of A
//Constructor of B
//Constructor of C
