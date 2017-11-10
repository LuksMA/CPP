// Allocate a variable dynamically.
#include <iostream>

int main()
{
//	int *ptr = new int;
//	*ptr = 4;
	int *ptr = new int (4);
	std::cout << *ptr << std::endl;
	return 0;
}
