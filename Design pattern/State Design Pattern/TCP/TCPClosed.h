#ifndef TCPCLOSED_H_INCLUDED
#define TCPCLOSED_H_INCLUDED

#include <iostream>
#include "TCPConnection.h"

class TCPClosed : public TCPState
{
    public:
        static TCPClosed* Instance();
        virtual void Open(TCPConnection *tc);
        virtual string CurrentState(){return m_currState;}

    private:
        TCPClosed():m_currState("Closed"){}
        static TCPClosed* m_ti;
        string m_currState;
};


#endif // TCPCLOSED_H_INCLUDED
