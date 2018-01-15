// Print all possible combinations of r elements in a given array of size n
// Given an array of size n, generate and print all possible combinations of r elements in array.
// For example, if input array is {1, 2, 3, 4} and r is 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.

// Program to print all combination of size r in an array of size n
#include <stdio.h>
void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(char arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    char data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%c ", data[j]);
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

// Driver program to test above functions
int main()
{
    char carr[]= {'A','B','C','D','E'};
    int cr = 2;
    int n = sizeof(carr)/sizeof(carr[0]);  // Length of the array
    printCombination(carr, n, cr);
}


//A B
//A C
//A D
//A E
//B C
//B D
//B E
//C D
//C E
//D E
