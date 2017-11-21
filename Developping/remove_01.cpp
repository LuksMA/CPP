#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>

using namespace std;

class A
{
public:
    A(int n) : m_n(n)
    {
    }

    int get() const
    {
        return m_n;
    }
private:
    int m_n;
};

bool lessThan9(const A& a)
{
    return a.get() < 9;
}

//Or if you want for a generic number
//struct Remover : public std::binary_function<A,int,bool>
//{
//public:
//    bool operator()(const A& a, int n)const
//    {
//        return a.get() < n;
//    }
//};

int main()
{
    std::vector<A> a;
    a.push_back(A(10));
    a.push_back(A(8));
    a.push_back(A(11));
    a.push_back(A(3));

    a.erase(std::remove_if(a.begin(), a.end(), lessThan9), a.end());

    //Using the user-defined functor
//    a.erase(std::remove_if(a.begin(), a.end(), std::bind2nd(Remover(), 9)), a.end());

    return 0;
}
