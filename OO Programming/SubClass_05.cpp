/// Calling parameterized base class constructor
#include <iostream>

using namespace std;

class A
{
	public:
		A( int l )
		{
			cout << "Length : " << l << endl;
		}
};

class B : public A
{
	public:
		B() : A(20)
		{
			cout << "This is constructor of B" << endl;
		}
};

int main()
{
	B b;
	return 0;
}

//Output:
//Length : 20
//This is constructor of B
