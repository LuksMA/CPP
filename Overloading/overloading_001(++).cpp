// increment counter variable with ++ operator
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter
{
private:
    unsigned int count; //count
public:
    Counter() : count(0) //constructor
    { }
    unsigned int get_count() //return count
    {
        return count;
    }
    void operator ++ () //increment (prefix)
    {
        ++count;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    Counter c1, c2; //define and initialize
    cout << "c1=" << c1.get_count()<<endl; //display
    cout << "c2=" << c2.get_count()<<endl;
    ++c1; //increment c1
    ++c2; //increment c2
    ++c2; //increment c2

    cout << "After ++:\n";
    cout << "c1=" << c1.get_count()<<endl; //display again
    cout << "c2=" << c2.get_count()<<endl;
    return 0;
}


//c1=0
//c2=0
//After ++:
//c1=1
//c2=2
