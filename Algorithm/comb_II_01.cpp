#include <vector>
#include <iostream>
using namespace std;

void printAll(const vector<vector<string> > &allVecs, size_t vecIndex, string strSoFar)
{
    if (vecIndex >= allVecs.size())
    {
        cout << strSoFar << endl;
        return;
    }
    for (size_t i=0; i<allVecs[vecIndex].size(); i++)
        printAll(allVecs, vecIndex+1, strSoFar+allVecs[vecIndex][i]+" ");
}

int main()
{

    vector <string> Vec1;
    Vec1.push_back("1");
    Vec1.push_back("2");
//    Vec1.push_back("3");

    vector <string> Vec2;
    Vec2.push_back("C");
    Vec2.push_back("G");
    Vec2.push_back("A");

    vector <string> Vec3;
    Vec3.push_back("I");
    Vec3.push_back("II");
    Vec3.push_back("III");

    vector<vector<string>> xt;
    xt.push_back(Vec1);
    xt.push_back(Vec2);
    xt.push_back(Vec3);

    printAll(xt, 0, "");
}


//1 C I
//1 C II
//1 C III
//1 G I
//1 G II
//1 G III
//1 A I
//1 A II
//1 A III
//2 C I
//2 C II
//2 C III
//2 G I
//2 G II
//2 G III
//2 A I
//2 A II
//2 A III



