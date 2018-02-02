#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


class AbstractSort
{
    // Shell sort
public:
    void sort(int v[], int n)
    {
        for (int g = n / 2; g > 0; g /= 2)
            for (int i = g; i < n; i++)
                for (int j = i - g; j >= 0; j -= g)
                    if (needSwap(v[j], v[j + g]))
                        doSwap(v[j], v[j + g]);
    }
private:
    virtual int needSwap(int, int) = 0;
    void doSwap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
};

class SortUp: public AbstractSort
{
    /* virtual */
    int needSwap(int a, int b)
    {
        return (a > b);
    }
};
class SortDown: public AbstractSort
{
    /* virtual */
    int needSwap(int a, int b)
    {
        return (a < b);
    }
};

int main()
{
    const int NUM = 10;
    int array[NUM];
    srand((unsigned)time(0));
    for (int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 10+1;
        cout << array[i] << ' ';
    }
    cout << '\n';

    AbstractSort *sortObjects[] =
    {
        new SortUp, new SortDown
    };
    sortObjects[0]->sort(array, NUM);
    for (int u = 0; u < NUM; u++)
        cout << array[u] << ' ';
    cout << '\n';

    sortObjects[1]->sort(array, NUM);
    for (int d = 0; d < NUM; d++)
        cout << array[d] << ' ';
    cout << '\n';
    system("pause");
}

//3 9 1 8 3 3 5 3 9 8
//1 3 3 3 3 5 8 8 9 9
//9 9 8 8 5 3 3 3 3 1
