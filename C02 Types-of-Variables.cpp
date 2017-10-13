#include <iostream>

using namespace std;

main()
{
    //TYPE_OF_VARIABLE nameOfVariable;
    //TYPE_OF_VARIABLE nameOfVariable1, nameOfVariable2, nameOfVariable3;

    int a = 40, b = 0, c = 20; //-2billions to 2 billions, 4 BYTES

    cout << "a : " << a << " address: " << &a << endl;
    cout << "b : " << b << " address: " << &b << endl;
    cout << "c : " << c << " address: " << &c << endl;

    short t1 = 5; //-32768 to 32767, 2 BYTES

    cout << t1 << endl;

    float t2 = 5.12; //4 BYTES nr that are up to 38 zeros
    double t3 = 5.12; //8 BYTES nr that are up to 308 zeros 5.61235123512351

    cout << t2 << endl;
    cout << t3 << endl;

    char t4; //character

    t4 = 'a';
    cout << t4 << endl;

    string t5 = "Hello World! :-)";

    cout << t5 << endl;

    string x = "part1";
    string y = "part2";
    string combinedStrings = x + " " + y;

    cout << combinedStrings << endl;
    //boolean | true of false, SO FALSE IS ALWAYS 0, EVERY OTHER NUMBER is TRUE, 1 is representing TRUE
    bool t6 = 0;

    cout << t6 << endl;

    //for unsigned short int, 0 to 65535
    unsigned short t7 = 3700;
    cout << t7 << endl;

    const string NAMEOFGAME = "Conqueror of C++";

    cout << NAMEOFGAME << endl;
   // NAMEOFGAME = "something";

}
