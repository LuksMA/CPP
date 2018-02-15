#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Observer
{
    public:
        Observer();
        virtual ~Observer();
        virtual void update(Subject * sub) = 0;
};

#endif // OBSERVER_H
