#include<omp.h>
#include<iostream>

using namespace std;

int main(){

    #pragma omp parallel
    {
        cout<<"Hello world\n";
    }
    cout<<"Program exit.";
}


//Hello world
//Hello world
//Hello world
//Hello world
//Program exit.
