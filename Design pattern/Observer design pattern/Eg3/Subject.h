#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
using namespace std;

class Subject
{

public:
	Subject();
	virtual ~Subject();
	Observer *m_Observer;

	void attach(Observer * pObeserver);
	void detach(Observer * pObeserver);
	void notify();

	virtual int getState() = 0;
	virtual void setState(int i)= 0;

private:
	vector<Observer*> m_vtObj;

};

#endif // SUBJECT_H
