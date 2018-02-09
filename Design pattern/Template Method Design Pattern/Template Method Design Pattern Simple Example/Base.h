#ifndef BASE_H
#define BASE_H

#include <iostream>

using namespace std;

class Base
{
    public:
        void execute();
        virtual void ph1() = 0;
        virtual void ph2() = 0;

    private:
        void a();
        void c();
        void e();
};

#endif // BASE_H
