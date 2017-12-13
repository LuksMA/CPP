#include<omp.h>
#include<iostream>

using namespace std;

static long num_steps = 100000000;
double step;


int main ()
{
    int i;
    double x,pi,sum = 0.0;
    step = 1.0/(double) num_steps;
//    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        double x;
        #pragma omp for reduction(+:sum)
        for(i=0;i<num_steps;i++){
            x = (i+0.5)*step;
            sum+=4.0/(1.0+x*x);
        }
    }

    cout<<step*sum;
}

