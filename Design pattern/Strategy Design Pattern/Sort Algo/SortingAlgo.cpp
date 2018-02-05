#include "SortingAlgo.h"

SortingAlgo::SortingAlgo()
{
    m_pComparator = new LesserComprataor();
}


void SortingAlgo::swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}


void SortingAlgo :: sort(std::vector<int> &arr, IComparator* pComparator)
{
    if(pComparator == nullptr)
        pComparator = m_pComparator;

    bool isSwapped = true;
    int x = 0;
    while (isSwapped)
    {
        isSwapped = false;
        x++;
        for (unsigned i = 0; i < arr.size() - x; i++)
        {
            if (pComparator->compare(arr[i], arr[i + 1]) )
            {
                swap(arr[i], arr[i + 1]);
                isSwapped = true;
            }
        }
    }
}
