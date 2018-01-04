#ifndef DYNARRAY_H
#define DYNARRAY_H


class Dynarray
{
private:
    int *pa;        // points to the array
    int length;     // the # elements
    int nextIndex;  // the next highest index value
public:
    Dynarray(int len);                         // the constructor
    ~Dynarray();                        // the destructor
    int& operator[](int index);         // the indexing operation
    void add(int val);                  // add a new value to the end
    int size();                         // return length
};

#endif // DYNARRAY_H
