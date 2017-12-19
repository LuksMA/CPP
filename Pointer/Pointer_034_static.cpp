// static functions and ID numbers for objects
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class gamma
{
private:
    static int total; //total objects of this class
// (declaration only)
    int id; //ID number of this object
public:
    gamma() //no-argument constructor
    {
        total++; //add another object
        id = total; //id equals current total
    }
    ~gamma() //destructor
    {
        total--;
        cout << "Destroying ID number " << id << endl;
    }
    static void showtotal() //static function
    {
        cout << "Total is " << total << endl;
    }
    void showid() //non-static function
    {
        cout << "ID number is " << id << endl;
    }
};
//--------------------------------------------------------------
int gamma::total = 0; //definition of total
////////////////////////////////////////////////////////////////
int main()
{
    gamma g1;
    gamma::showtotal();
    gamma g2, g3;
    gamma::showtotal();
    g1.showid();
    g2.showid();
    g3.showid();
    cout << "----------end of program----------\n";
    return 0;
}


//Total is 1
//Total is 3
//ID number is 1
//ID number is 2
//ID number is 3
//----------end of program----------
//Destroying ID number 3
//Destroying ID number 2
//Destroying ID number 1
