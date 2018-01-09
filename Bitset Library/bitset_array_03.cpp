#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int intarray[5] = { 5, 3, 4, 1, 2 };
    int cut[6] = {1, 2, 3, 4, 5, 6};

    bitset<6>* m = new bitset<6>[5];

    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            if(intarray[i]<cut[j])
            {
                m[i][j] = 1;
            }
        }
    }



    cout<<"  [ ";
    for(int i=0; i<6; ++i)
    {
        cout<<cut[i]<<' ';
    }
    cout<<']'<<endl;

    for(int i=0; i<5; ++i)
    {
        cout<<intarray[i]<<" [ ";
        for(int j=0; j<6; ++j)
        {
            cout<<m[i][j]<<' ';
        }
        cout<<']'<<endl;
    }
}
