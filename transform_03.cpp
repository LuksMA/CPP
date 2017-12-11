// C++ STL algorithm, transform()
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

// the function object multiplies an element by a Factor
template <class Type> class MultValue
{
private:
// the value to multiply by
    Type Factor;
public:
// constructor initializes the value to multiply by
    MultValue(const Type &_Val) : Factor(_Val) { }
// the function call for the element to be multiplied
    int operator()(Type &elem) const
    {
        return (elem * Factor);
    }
};
int main(void)
{
// vector container
    vector <int> vec1, vec2(7), vec3(7);
// vector iterator
    vector <int>::iterator Iter1, Iter2, Iter3;

// pushing the data in range
    for(int i = -4; i <= 2; i++)
        vec1.push_back(i);

// constructing vec1 vector
    cout<<"Original vec1 vector data: ";
    for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)
        cout<<*Iter1<<" ";
    cout<<endl;
    /// Original vec1 vector data: -4 -3 -2 -1 0 1 2

// modifying the vec1 vector in place
    transform(vec1.begin(), vec1.end(), vec1.begin(), MultValue<int>(2));
    cout<<"\nThe elements of the vec1 vector multiplied by 2 in place gives:"
        <<"\nvec1mod data: ";
    for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)
        cout<<*Iter1<<" ";
    cout<<endl;
    /// vec1mod data: -8 -6 -4 -2 0 2 4

// using transform() to multiply each element by a factor of 5
    transform(vec1.begin(), vec1.end(), vec2.begin(), MultValue<int>(5));
    cout<<"\nMultiplying the elements of the vec1mod vector\n"
        <<"by the factor 5 & copying to vec2 gives:\nvec2 data: ";
    for(Iter2 = vec2.begin(); Iter2 != vec2.end(); Iter2++)
        cout<<*Iter2<<" ";
    cout<<endl;
    /// vec2 data: -40 -30 -20 -10 0 10 20

// the second version of transform used to multiply the elements of the vectors vec1mod & vec2 pairwise
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(),
              multiplies<int>());
    cout<<"\nMultiplying elements of the vec1mod and vec2 vectors pairwise "
        <<"gives:\nvec3 data: ";
    for(Iter3 = vec3.begin(); Iter3 != vec3.end(); Iter3++)
        cout<<*Iter3<<" ";
    cout<<endl;
    return 0;
    /// vec3 data: 320 180 80 20 0 20 80
}
