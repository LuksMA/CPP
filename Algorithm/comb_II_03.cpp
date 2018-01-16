#include <vector>
#include <iostream>
using namespace std;


int main()
{

    vector<int> Vec1;
    Vec1.push_back(1);
    Vec1.push_back(2);
    Vec1.push_back(3);

    vector <int> Vec2;
    Vec2.push_back(5);
    Vec2.push_back(6);
    Vec2.push_back(7);
    Vec2.push_back(8);

    vector <int> Vec3;
    Vec3.push_back(11);
    Vec3.push_back(12);
    Vec3.push_back(13);

    vector<vector<int>> allVecs;
    allVecs.push_back(Vec1);
    allVecs.push_back(Vec2);
    allVecs.push_back(Vec3);

    size_t max = 1;

    for (auto const &v : allVecs)
        max *= v.size();
//    cout<<max<<endl;

    for (size_t i=0; i<max; i++)
    {
        auto temp = i;
        for (auto const &vec : allVecs)
        {
            auto index = temp % vec.size();
            temp /= vec.size();
            std::cout << vec[index] << ' ';
        }
        std::cout << '\n';
    }
}


//1 5 11
//2 5 11
//3 5 11
//1 6 11
//2 6 11
//3 6 11
//1 7 11
//2 7 11
//3 7 11
//1 8 11
//2 8 11
//3 8 11
//1 5 12
//2 5 12
//3 5 12
//1 6 12
//2 6 12
//3 6 12
//1 7 12
//2 7 12
//3 7 12
//1 8 12
//2 8 12
//3 8 12
//1 5 13
//2 5 13
//3 5 13
//1 6 13
//2 6 13
//3 6 13
//1 7 13
//2 7 13
//3 7 13
//1 8 13
//2 8 13
//3 8 13

