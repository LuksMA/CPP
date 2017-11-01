#include <vector>
#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>

///  Generate 10 continues variables in Uniform distribution
///  Convert double to int by "floor"

using namespace std;

int main(){
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(1.0, 100.0);


    vector<int> v;
    vector<int>::const_iterator i;
    printf("Random numbers: \n");
    for (int n = 0; n < 10; ++n) {
        double temp = dis(gen);
        cout << temp << ' ';
        v.push_back(floor(temp)); //Each call to dis(gen) generates a new random double
    }
    printf("\n");
    printf("Integer Vector: \n");
    for(i=v.begin(); i!=v.end(); ++i){
        cout<<(*i)<<' ';
    }
}
