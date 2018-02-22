#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
using namespace std;

class Singleton
{

public:
	virtual ~Singleton();
	Singleton* m_Singleton;

	static Singleton* getInstance();
	void singletonOperation();

private:
	static Singleton* instance;
	Singleton();
};

#endif // SINGLETON_H
