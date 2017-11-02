/// Implement different operations on pairs.
///
/// Input:
/// The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of input contains an integer Q denoting the no of queries . Then in the next line are Q space separated queries .
/// A query can be of five types
/// 1. a s x y (Adds a pair with string s and values x,y to the vector A at the end )
/// 2. b (returns the size of the vector A)
/// 3. c (prints space separated values of each element of the vector of pairs A)
/// 4. d (sorts the pair's array with respect to the values x,y in ascending order)
///
///
/// Output:
/// The output for each test case will  be space separated integers denoting the results of each query .


//Example:
//
//Input
//2
//5
//a ga 4 5 a ra 1 2 a sh 1 1 d c
//4
//a geeks 10 12  a code 11 11 b c
//
//Output
//sh 1 1 ra 1 2 ga 4 5
//2 geeks 10 12 code 11 11

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

void add_pair(vector<pair<string,pair<int,int> > > &A, string str, int x, int y);
int get_size(vector<pair<string,pair<int,int> > > &A);
void print_values(vector<pair<string,pair<int,int> > > &A);
void sort_pair(vector<pair<string,pair<int,int> > > &A);


int main(){
    vector<pair<string,pair<int,int> > > VQ;
    add_pair(VQ,"ga",4,5);
    add_pair(VQ,"ra",1,2);
    add_pair(VQ,"sh",1,1);

    printf("Size of Vector: %d", get_size(VQ));
    printf("\n");

    print_values(VQ);
    printf("\n");

    sort_pair(VQ);
    print_values(VQ);

    return 0;
}

void add_pair(vector<pair<string,pair<int,int> > > &A, string str, int x, int y){
    A.push_back(make_pair(str,make_pair(x,y)));
}


int get_size(vector<pair<string,pair<int,int> > > &A){
    return A.size();
}


void print_values(vector<pair<string,pair<int,int> > > &A){
    vector<pair<string,pair<int,int> >>::const_iterator i;
    for(i=A.begin(); i!=A.end(); ++i){
        cout<<(*i).first<< ' '<<(*i).second.first<<' '<<(*i).second.second<<endl;
    }
}


bool sortbysec( pair<string,pair<int,int> >a, pair<string,pair<int,int> > b)
{
    return (a.second < b.second);
}

void sort_pair(vector<pair<string,pair<int,int> > > &A){
    sort(A.begin(), A.end(),sortbysec);
}


