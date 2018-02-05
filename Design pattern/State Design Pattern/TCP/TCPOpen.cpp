#include "TCPOpen.h"
#include "TCPEstablished.h"

using namespace std;

TCPOpen* TCPOpen::m_ti = 0;

TCPOpen* TCPOpen::Instance()
{
    if(!m_ti)
    {
        m_ti = new TCPOpen();
    }
    else
    {
        return m_ti;
    }

    return m_ti;
}
void TCPOpen::Listen(TCPConnection *tc)
{
    cout << "Listening" << endl;
    ChangeState(tc, TCPEstablished::Instance());
}
