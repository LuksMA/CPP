// ref.cpp
// demonstrates passing by reference
#include <iostream>
using namespace std;

int main()
{
    void intfrac(float, float&, float&); //declaration
    float number = 99.44, intpart, fracpart; //float variables

    cout << "Enter a real number: "<<99.44; //number from user
    intfrac(number, intpart, fracpart); //find int and frac
    cout << "\nInteger part is " << intpart //print them
         << ", fraction part is " << fracpart << endl;

    return 0;
}
//--------------------------------------------------------------
// intfrac()
// finds integer and fractional parts of real number
void intfrac(float n, float& intp, float& fracp)
{
    long temp = static_cast<long>(n); //convert to long,
    intp = static_cast<float>(temp); //back to float
    fracp = n - intp; //subtract integer part
}
