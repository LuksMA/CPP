#include <iostream>

using namespace std;

int main()
{
    int intarray[5] = { 5, 3, 4, 1, 2 };
    int cut[6] = {1, 2, 3, 4, 5, 6};
    int m[5][6] = {0};

    for(int i=0; i<5; ++i){
        for(int j=0; j<6; ++j){
            if(intarray[i]<cut[j]){
                m[i][j] = 1;
            }
        }
    }

    cout<<"  [ ";
    for(int i=0; i<6; ++i){
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

//  [ 1 2 3 4 5 6 ]
//5 [ 0 0 0 0 0 1 ]
//3 [ 0 0 0 1 1 1 ]
//4 [ 0 0 0 0 1 1 ]
//1 [ 0 1 1 1 1 1 ]
//2 [ 0 0 1 1 1 1 ]
