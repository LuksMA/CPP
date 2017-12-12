#include<omp.h>
#include<iostream>

using namespace std;

#define ARRSIZE 20

int main(){
    int myid,size;
    int i;
    int *A,*B,*C;

    // Allocate and initialize the arrays
    A = (int *)malloc(ARRSIZE*sizeof(int));
    B = (int *)malloc(ARRSIZE*sizeof(int));
    C = (int *)malloc(ARRSIZE*sizeof(int));

    // Initialize data to some value
    for(i=0;i<ARRSIZE;++i){
        A[i] = i;
        B[i] = i;
    }

    // print the data
    cout<<"Initial data:\n";
    for(i=0;i<ARRSIZE;++i){
        cout<<A[i]<<'\t'<<B[i]<<endl;
    }

    // Perform operations in parallel
    #pragma omp parallel for default(none) shared(A,B,C)
    for(i=0;i<ARRSIZE;++i){
        C[i] = A[i] + B[i];
    }

    // Print the data
    cout<<"\nVector addition output:\n";
    for(i=0;i<ARRSIZE;++i){
        cout<<C[i]<<endl;
    }
    cout<<"Program exit.";

}

//Initial data:
//0       0
//1       1
//2       2
//3       3
//4       4
//5       5
//6       6
//7       7
//8       8
//9       9
//10      10
//11      11
//12      12
//13      13
//14      14
//15      15
//16      16
//17      17
//18      18
//19      19
//
//Vector addition output:
//0
//2
//4
//6
//8
//10
//12
//14
//16
//18
//20
//22
//24
//26
//28
//30
//32
//34
//36
//38
//Program exit.
