//CPP program to illustrate auto-initializing of pair STL
#include <iostream>
#include <utility>

using namespace std;

int main(){
    //pair <string, double> PAIR4;
    pair <string, double> PAIR4 ;
    PAIR4 = make_pair ("GeeksForGeeks is Best",4.56);

    cout<<PAIR4.first<<' '<<PAIR4.second;

    return 0;
}
