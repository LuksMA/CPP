#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

main(){

    vector<int> q;
    q.push_back(10); q.push_back(20); q.push_back(30);

    vector<int> v;
    for(int i=0; i<5; ++i){
        v.push_back(i);
    }
    /// v contains 0 1 2 3 4

    /// Size of the vector
    printf("Size of vector q: %d \n",q.size()); // 3
    printf("Size of vector V: %d \n",v.size()); // 5
    printf("\n");

    /// Visit element
    printf("The first element in vector q is %d \n",*q.begin()); // 10
    printf("The second element in vector q is %d \n",q[1]);      // 20
    printf("The last element in vector q is %d \n",q.back());    // 30
    printf("The end element in vector q is %d \n",*q.end());     // 0
    printf("\n");

    /// Loop the vector
    /// The function begin( ) returns an iterator to the start of the vector.
    /// The function end( ) returns an iterator to the end of the vector.
    printf("vector v: \n");
    vector<int>::const_iterator i;
    for(i=v.begin(); i!=v.end(); ++i){
        std::cout<<(*i)<<std::endl;
    }

    printf("vector q: \n");
    for(i=q.begin(); i!=q.end(); ++i){
        std::cout << *i << ' ';
    }

}
