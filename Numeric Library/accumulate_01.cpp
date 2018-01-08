#include <iostream>
#include <functional>
#include <numeric>

int myfunction (int x, int y)
{
    return x+2*y;
}
struct myclass
{
    int operator()(int x, int y)
    {
        return x+3*y;
    }
} myobject;

int main ()
{
    int init = 100;
    int numbers[] = {5,10,20};

    std::cout << "using default accumulate: ";
    std::cout << std::accumulate(numbers,numbers+3,init);  // 100+5+10+20 = 135
    std::cout << '\n';

    std::cout << "using functional's minus: ";
    std::cout << std::accumulate (numbers, numbers+3, init, std::minus<int>()); // 100 - (5+10+20) = 65;
    std::cout << '\n';

    std::cout << "using custom function: ";
    std::cout << std::accumulate (numbers, numbers+3, init, myfunction); // 100 + 5*2 + 10*2 + 20*2 = 170
    std::cout << '\n';

    std::cout << "using custom object: ";
    std::cout << std::accumulate (numbers, numbers+3, init, myobject); // 100 + 5*3 + 10*3 + 20*3 = 205
    std::cout << '\n';

    return 0;
}
