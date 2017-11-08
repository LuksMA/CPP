/// Use of static 01 (static function)
/// 'static' is used to make access to any data variable or function without making an object of that class.
/// It means that 'static' is used so that we can access any data variable or function without making an object of that class.

#include <iostream>

using namespace std;

class Rectangle
{
	public:
		static void printArea( int l, int b )
		{
			cout << l*b << endl;
		}
};
int main()
{
	Rectangle::printArea(4,7);
	return 0;
}
