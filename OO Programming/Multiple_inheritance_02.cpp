#include <iostream>

using namespace std;

class P1
{
	public:
		P1()
		{
			cout << "Constructor of P1" << endl;
		}
};

class P2
{
	public:
		P2()
		{
			cout << "Constructor of P2" << endl;
		}
};

class A : public P2, public P1
{
	public:
		A()
		{
			cout << "Constructor of A" << endl;
		}
};

int main()
{
	A a;
	return 0;
}
