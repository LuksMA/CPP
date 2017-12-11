// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

using namespace std;

template<class T>
void print1DVector(vector<T> const &vectIn)
{
    cout<<"[ ";
    for(const auto &row : vectIn)
    {
        cout<<row<<' ';
    }
    cout<<']';
}

int op_increase (int i)
{
    return ++i;
}

int main ()
{
    std::vector<int> foo;
    std::vector<int> bar;

    // set some values:
    for (int i=1; i<6; i++)
        foo.push_back (i*10);                         // foo: 10 20 30 40 50

    bar.resize(foo.size());                          // allocate space bar:0 0 0 0 0

    std::transform (foo.begin(), foo.end(), bar.begin(), op_increase);
    // foo: 10 20 30 40 50
    // bar: 11 21 31 41 51

    // std::plus adds together its two arguments:
    std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
    //     foo: 21 41 61 81 101 = previous_foo + previous_bar
    //     bar: 11 21 31 41 51




    return 0;
}
