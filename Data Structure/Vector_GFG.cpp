/// Input:
/// The first line of input contains an integer T denoting the no. of test cases. Then T test cases follow.
/// The first line of input contains an integer Q denoting the no. of queries. Then in the next line are Q space separated queries .
/// A query can be of six types
/// 1. a x (Adds an element x to the vector A at the end )
/// 2. b (Sorts the vector A in ascending order )
/// 3. c (Reverses the vector A)
/// 4. d (prints the size of the vector)
/// 5. e (prints space separated values of the vector)
/// 6. f  (Sorts the vector A in descending order)

// http://practice.geeksforgeeks.org/problems/c-stl-set-1-vector/1/?ref=self
//Example:
//
//Input
//2
//6
//a 4 a 6 a 7 b c e
//4
//a 55 a 11 d e
//
//Output
//7 6 4
//2 55 11


//Explanation :
//For the first test case
//There are six queries. Queries are performed in this order
//1. a 4 { Vector has 4  }
//2. a 7 {vector has 7 }
//3. a 6 {vector has 6}
//4. b {sorts the vector in ascending order, vector now is 5 6 7}
//5. c {reverse the vector }
//6. e {prints the element of the vectors 7 6 4}
//
//For the sec test case
//There are four queries. Queries are performed in this order
//1. a 55  (vector A has 55}
//2. a 11  (vector A has 55 ,11}
//3. d      (prints the size of the vector A ie. 2 )
//4. e      (prints the elements of the vector A ie 55 11)


#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void add_to_vector(vector<int> &A,int x);    /// inserts an element x
void sort_vector_asc(vector<int> &A);      /// sort the vector A in ascending order
void reverse_vector(vector<int> &A);       /// reverses the vector A
int size_of_vector(vector<int> &A);        /// returns the size of the vector  A
void sort_vector_desc(vector<int> &A);     /// sorts the vector A in descending order
void print_vector(vector<int> &A);         /// prints space separated elements of vector A

int main(){
    vector<int> VQ;
    add_to_vector(VQ,10);
    add_to_vector(VQ,30);
    add_to_vector(VQ,20);

    printf("Original Vector: \n");
    print_vector(VQ);
    printf("\n");

    printf("Ascending sorted Vector: \n");
    sort_vector_asc(VQ);
    print_vector(VQ);
    printf("\n");

    printf("Size of Vector: %d", size_of_vector(VQ));
    printf("\n");

    printf("Descending sorted Vector: \n");
    sort_vector_desc(VQ);
    print_vector(VQ);
    printf("\n");

    return 0;
}

void add_to_vector(vector<int> &A,int x){
	A.push_back(x);
}

void sort_vector_asc(vector<int> &A){
    sort(A.begin(), A.end());
}

void reverse_vector(vector<int> &A){
    reverse(A.begin(), A.end());
}


int size_of_vector(vector<int> &A){
    return A.size();
}

void sort_vector_desc(vector<int> &A){
    sort(A.rbegin(), A.rend());
}


void print_vector(vector<int> &A){
    vector<int>::const_iterator i;
     for(i=A.begin(); i!=A.end(); ++i){
        std::cout<<(*i)<< ' ';
    }
}










