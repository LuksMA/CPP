#include <iostream>

using namespace std;

int main()
{
    const int X=20;
    const int Y=20;
    const int Z=20;

    int ***arr3D = new int**[X];
    for(int i =0; i<X; i++)
    {
        arr3D[i] = new int*[Y];
        for(int j =0; j<Y; j++)
        {
            arr3D[i][j] = new int[Z];
            for(int k = 0; k<Z; k++)
            {
                arr3D[i][j][k] = 0;
            }
        }
    }
}
