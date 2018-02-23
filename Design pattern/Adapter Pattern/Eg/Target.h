#ifndef TARGET_H
#define TARGET_H

#include <iostream>
using namespace std;

class Target
{

public:
	Target();
	virtual ~Target();

	virtual void request();

};

#endif // TARGET_H
