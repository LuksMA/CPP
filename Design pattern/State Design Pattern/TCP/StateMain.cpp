#include "TCPConnection.h"

using namespace std;

int main()
{
    //TCP operations are not in their real logical order
    //This is just to show how state pattern works.

    TCPConnection tco;

    cout << "### Test 1 ####" << endl;
    tco.Send();         //This will be rejected as conn is not established yet

    cout << "\n### Test 2 ####" << endl;
    tco.Open();
    tco.Listen();
    cout << "Current state : " << tco.CurrentState() << endl;
    tco.Send();
    tco.Recieve();
    tco.Close();

    cout << "\n### Test 3 ####" << endl;
    tco.Open();
    tco.Listen();
    tco.Open();         //This should be rejected as already open
    tco.Send();
    tco.Send();
    tco.Close();
    cout << "Current state : " << tco.CurrentState() << endl;

    return 0;
}
