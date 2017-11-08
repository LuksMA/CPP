/// Use of static 02 (static variable)
/// 'static' is used to make access to any data variable or function without making an object of that class.
/// It means that 'static' is used so that we can access any data variable or function without making an object of that class.
#include <iostream>

using namespace std;

class A
{
	public:
		static int a;
};

int A::a = 8;

int main()
{
	cout << A::a << endl;
	return 0;
}
