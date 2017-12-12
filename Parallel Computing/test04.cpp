#include<omp.h>
#include<iostream>

using namespace std;

int main(){

    int num_thds, myid;

    #pragma omp parallel
    {
        num_thds = omp_get_num_threads();
        myid = omp_get_thread_num();

        printf("\nHello world from thread num %d out of %d threads!",myid,num_thds);
    }
    cout<<"\nProgram exit.";
}


//Hello world from thread num 1 out of 4 threads!
//Hello world from thread num 2 out of 4 threads!
//Hello world from thread num 3 out of 4 threads!
//Hello world from thread num 0 out of 4 threads!
//Program exit.
