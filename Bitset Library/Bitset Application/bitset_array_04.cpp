#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int arr_1[5] = { 5, 3, 4, 1, 2 };
    int arr_2[5] = { 1, 2, 3, 4, 5 };

    int cut[6] = {1, 2, 3, 4, 5, 6};

    bitset<6>* m1 = new bitset<6>[5];
    bitset<6>* m2 = new bitset<6>[5];

    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            if(arr_1[i]<cut[j])
            {
                m1[i][j] = 1;
            }
            if(arr_2[i]<cut[j])
            {
                m2[i][j] = 1;
            }
        }
    }



    cout<<"m1:[ ";
    for(int i=0; i<6; ++i)
    {
        cout<<cut[i]<<' ';
    }
    cout<<']'<<endl;

    for(int i=0; i<5; ++i)
    {
        cout<<arr_1[i]<<"  [ ";
        for(int j=0; j<6; ++j)
        {
            cout<<m1[i][j]<<' ';
        }
        cout<<']'<<endl;
    }

    cout<<"\nm2:[ ";
    for(int i=0; i<6; ++i)
    {
        cout<<cut[i]<<' ';
    }
    cout<<']'<<endl;
    for(int i=0; i<5; ++i)
    {
        cout<<arr_2[i]<<"  [ ";
        for(int j=0; j<6; ++j)
        {
            cout<<m2[i][j]<<' ';
        }
        cout<<']'<<endl;
    }
}
