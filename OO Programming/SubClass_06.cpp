/// Calling parameterized base class constructor
#include <iostream>

using namespace std;

class A
{
	int l1;
	public:

		A( int z ) : l1(z)
		{
			cout << "l1 : " << l1 << endl;
		}
};

class B : public A
{
	int l2;
	public:
		B( int x, int y ) : A(x), l2(y)
		{
			cout << "l2 : " << l2 << endl;
		}
};

int main()
{
	B b( 5, 10 );
	return 0;
}

//Output:
//l1 : 5
//l2 : 10
