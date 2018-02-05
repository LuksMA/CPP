#ifndef TCPOPEN_H_INCLUDED
#define TCPOPEN_H_INCLUDED

#include <iostream>
#include "TCPConnection.h"

class TCPOpen : public TCPState
{
    public:
        static TCPOpen* Instance();
        virtual void Listen(TCPConnection *tc);
        virtual string CurrentState(){return m_currState;}
    private:
        TCPOpen():m_currState("Open"){}
        static TCPOpen* m_ti;
        string m_currState;
};


#endif // TCPOPEN_H_INCLUDED
