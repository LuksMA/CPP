#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    vector<int> res;
    int sz = numbers.size();
    int p = 0, q = sz-1;
    while (p<q)
    {
        int sum = numbers[p]+numbers[q];
        if (sum==target)
        {
            res.push_back(p+1);
            res.push_back(q+1);
            return res;
        }
        else if (sum<target)
        {
            p++;
        }
        else
        {
            q--;
        }
    }
    return res;
}




template<class T>
void print1DVector(vector<T> const &vectIn);


int main()
{
    vector<int> X = {2,7,11,15};
    print1DVector(twoSum(X,9));

    return 0;
}

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
