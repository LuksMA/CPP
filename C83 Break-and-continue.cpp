#include <iostream>

using namespace std;
/* loops - break and continue */

main()
{
    /*
        1 2 3 4 5  6  7  8  9  10
        2 4 6 8 10 12 14 16 18 20
        3 6 9 12 15 ....
        4 ...
        5 ...
    */
/*
    for (int i = 1; i <= 10; i++) //amount of rows, length of column
    {

        if (i == 5)
            continue; //EVERYTHING AFTER continue instruction WONT BE executed BUT LOOP WON'T END BECAUSE OF IT

        if (i == 5)
            break; //EVERYTHING after break WON't be executed AND we are LEAVING the ACTUAL LOOP


        for (int j = 1; j <= 10; j++) //amount of columns, length of row
        {
            if (j == 5)
                continue;
            cout.width(4);
            cout << i * j;
        }
        cout << endl;
    }
*/


    for (int i = 1, j = 1; i <= 10; i++)
    {
        cout.width(4);
        cout << i * j;

        if (i == 10)
        {
            j++;
            i = 0;
            cout << endl;
        }

        if (j == 10 + 1)
            break;
    }
}
