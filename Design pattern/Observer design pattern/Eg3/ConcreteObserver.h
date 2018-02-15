#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H


#include "Observer.h"
#include "Subject.h"
#include <string>
#include <iostream>
using namespace std;

class ConcreteObserver : public Observer
{
    public:
        ConcreteObserver (string name);
        virtual ~ConcreteObserver ();
        void update(Subject * sub);

    private:
        string m_objName;
        int m_observerState;
};
#endif // CONCRETEOBSERVER_H
