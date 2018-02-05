#include "TCPClosed.h"
#include "TCPConnection.h"
#include "TCPOpen.h"

using namespace std;

TCPClosed* TCPClosed::m_ti = 0;

TCPClosed* TCPClosed::Instance()
{
    if(!m_ti)
    {
        m_ti = new TCPClosed();
    }
    else
    {
        return m_ti;
    }

    return m_ti;
}

void TCPClosed::Open(TCPConnection *tc)
{
    cout << "Connection open" << endl;
    ChangeState(tc, TCPOpen::Instance());
}
