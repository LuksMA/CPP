#include "SearchBehavior.h"
#include "SortBehavior.h"
#include "Merge.h"
#include "Quick.h"
#include "Heap.h"
#include "BinaryTree.h"
#include "HashTable.h"
#include "Sequential.h"
#include "Collection.h"
#include <iostream>


using namespace std;

int main()
{
    Merge merge;
    Quick quick;
    Heap heap;

    Sequential sequential;
    BinaryTree binaryTree;
    HashTable hashTable;

    Collection colA;
    colA.set_sort(&merge);
    colA.sort();

    Collection colB;
    colB.set_search(&binaryTree);
    colB.search();

    return 0;
}

//Merge sort()
//BinaryTree search()
