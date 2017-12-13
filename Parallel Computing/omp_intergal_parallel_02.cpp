#include<omp.h>
#include<iostream>

using namespace std;

static long num_steps = 100000000;
double step;

#define NUM_THREADS 4

int main ()
{

    double pi;
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        int i,id,nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        for(i = id;i<num_steps;i=i+nthrds){
            x = (i+0.5)*step;
            #pragma omp critical
            pi+=4.0/(1.0+x*x);
        }

    }

    cout<<pi*step;
}

