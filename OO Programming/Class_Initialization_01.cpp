#include <iostream>

using namespace std;

class Rectangle
{
	int length;
	int breadth;
	public:
		Rectangle() : length(7), breadth(4)
		{

		}
		int printArea()
		{
			return length * breadth;
		}
};

int main()
{
	Rectangle rt;
	cout << rt.printArea() << endl;
	return 0;
}
