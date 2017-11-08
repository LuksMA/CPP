#include <iostream>

using namespace std;

class Rectangle
{
	int length;
	int breadth;
	public:
		Rectangle( int l, int b ) : length(l), breadth(b)
		{

		}
		int printArea()
		{
			return length * breadth;
		}
};

int main()
{
	Rectangle rt( 7, 4 );
	cout << rt.printArea() << endl;
	return 0;
}
