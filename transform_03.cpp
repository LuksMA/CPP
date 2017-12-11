#include<iostream>
#include<vector>
#include<algorithm> //for the transform() function

using namespace std;

int increase (int i) { return ++i; }
int sum (int i, int j) { return i+j; }

int main()
{
  int someNums[] = {10,20,30,40,50}; //Array of 5 values
  //Another way to initialise a vector using the iterator constructor
  vector<int> vectorOne (someNums, someNums + sizeof(someNums) / sizeof(int));
  vector<int> vectorTwo;
  vector<int>::iterator it;

  cout<<"vectorOne elements are : ";
  for(unsigned int i = 0; i < vectorOne.size(); ++i)
    cout<<vectorOne[i]<<" ";
  cout<<endl;

  vectorTwo.resize(vectorOne.size()); //allocate space

  //OutputIterator transform ( InputIterator first1, InputIterator last1,
  //                           OutputIterator result, UnaryOperator op );
  std::transform(vectorOne.begin(), vectorOne.end(), vectorTwo.begin(), increase);

  cout<<"\nAfter transform with increase:"<<endl;
  cout<<"vectorOne elements are : ";
  for(unsigned int i = 0; i < vectorOne.size(); ++i)
    cout<<vectorOne[i]<<" ";
  cout<<endl;
  cout<<"vectorTwo elements are : ";
  for(unsigned int i = 0; i < vectorTwo.size(); ++i)
    cout<<vectorTwo[i]<<" ";
  cout<<endl;

  //OutputIterator transform ( InputIterator1 first1, InputIterator1 last1,
  //                           InputIterator2 first2, OutputIterator result,
  //                           BinaryOperator binary_op );
  transform (vectorOne.begin(), vectorOne.end(), vectorTwo.begin(), vectorOne.begin(), sum);

  cout<<"\nAfter transform with sum:"<<endl;
  cout<<"vectorOne elements are : ";
  for(unsigned int i = 0; i < vectorOne.size(); ++i)
    cout<<vectorOne[i]<<" ";
  cout<<endl;
  cout<<"vectorTwo elements are : ";
  for(unsigned int i = 0; i < vectorTwo.size(); ++i)
    cout<<vectorTwo[i]<<" ";
  cout<<endl;

  return 0;
}
