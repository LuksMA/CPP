#ifndef B_H
#define B_H

#include "I.h"

class D: public I
{
    public:
        D(I *inner);
        ~D();
        void do_it();

    private:
        I *m_wrappee;
};

#endif // B_H
