# include <iostream>

using namespace std;

main() {
    char a = 'A';   //character 1 byte -128 to 127
    int b = 10;    //integer 4 bytes -2147483648 to 2147483647
    short c = 10;  //short integer 2 bytes -32768 to 3276
    float d = 10.15;  //floating point 4 bytes +/- 3.4e +/- 38 (~7 digits)
    double e = 10.29; //double floating point 8 bytes +/- 1.7e +/- 308 (~15 digits)

    cout << a << endl;
    cout << &a << endl;
    cout << b << endl;
    cout << &b << endl;
    cout << c << endl;
    cout << &c << endl;
    cout << d << endl;
    cout << &d << endl;
    cout << e << endl;
    cout << &e << endl;

}
