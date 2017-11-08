## Functions of vectors
#### 1.  size() function returns the length (number of elements in the vector)
#### 2.  at function is used to access the element at specified position (index), eg. marks.at(i)
#### 3.  front function returns the first element of a vector, eg. marks.front()
#### 4.  back() function returns the last element of a vector, eg. marks.back()
#### 5.  empty(), checks whether a vector contains any element or not. 
####     It returns 1 if the length of a vector is 0 and 0 if it contains some element.
#### 6.  resize(), resizes a vector so that it contains the specified number of elements.
#### 7.  assign function It assigns new contents to the vector and replaces its current contents, eg. v.assign(7, 40)
#### 8.  push_back(), adds a new element at the end of the vector 
#### 9.  pop_back(), removes the last element in the vector
#### 10. reserve(), increases the capacity of the vector if the desired number of elements is greater than the capacity of the vector.
#### 11. insert(), inserts a new element in a vector before the element at the specified position.
##### auto it = v.begin();
##### v.insert(it,000); - We inserted 0 at the beginning of the vector.
##### v.insert(it,3,333); - We inserted 333 thrice at the beginning of the vector.
##### v.insert(it+4, v1.begin(), v1.end()); - We inserted the entire vector v1 (v1.begin(), v1.end()) at the 4th position of the vector v.
#### 12. erase function removes either a single element or a range of elements from a vector, 
##### v1.erase(v1.begin()+4);  // removing a single element at position 4
##### v2.erase(v2.begin()+1, v2.begin()+3);   // removing range of elements from position 1 till 2
#### 13. clear removes all elements of a vector.
#### 14. swap, swaps the contents.
##### vector<int> v1 = {1, 2, 3};
##### vector<int> v2 = {4, 5, 6};
##### v1.swap(v2);  

    
