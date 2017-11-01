#include <vector>
#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>
#include <algorithm>

///  Generate 10 continues variables in Uniform distribution
///  Convert double to int by "floor"
///  Max and Min number
///  Sort a vector


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
    printf("\n");


    /// Max
    vector<int>::iterator result;
    result = max_element(v.begin(), v.end());
    printf("Maximum number: %d \n",*result);
    /// Min
    result = min_element(v.begin(), v.end());
    printf("Minimum number: %d \n",*result);

    /// Sort
    sort(v.begin(), v.end());
    printf("Sorted Vector: \n");
    for(i=v.begin(); i!=v.end(); ++i){
        cout<<(*i)<<' ';
    }
    printf("\n");
}
