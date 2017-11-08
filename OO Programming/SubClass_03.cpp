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

int main()
{
	B b;
	return 0;
}

// Output:
// Constructor of A
// Constructor of B
