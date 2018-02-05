#ifndef TCPCONNECTION_H_INCLUDED
#define TCPCONNECTION_H_INCLUDED

#include <iostream>
#include <string>
#include "TCPState.h"

using namespace std;

class TCPState;

class TCPConnection
{
    public:
        TCPConnection();
        ~TCPConnection();

        void Init();
        void Open();
        void Close();
        void Send();
        void Recieve();
        void Listen();

        string CurrentState();

    protected:
        void ChangeState(TCPState* a_s);

    private:
        friend class TCPState;
        TCPState* m_st;
};


#endif // TCPCONNECTION_H_INCLUDED
