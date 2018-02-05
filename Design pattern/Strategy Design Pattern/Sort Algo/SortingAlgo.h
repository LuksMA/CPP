#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include "IComparator.h"
#include "LesserComprataor.h"
#include <vector>

using namespace std;

class SortingAlgo
{
    public:
        SortingAlgo();
        void sort(vector<int> &arr, IComparator* pComparator = nullptr);
    private:
        IComparator * m_pComparator;
        void swap(int &x, int &y);
};

#endif // SORTINGALGO_H
