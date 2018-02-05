#ifndef COLLECTION_H
#define COLLECTION_H

#include "SearchBehavior.h"
#include "SortBehavior.h"


class Collection
{
    public:
        Collection();
        void set_sort(SortBehavior* s);
        void set_search(SearchBehavior* s);
        void sort() const;
        void search() const;

    private:
        SortBehavior* m_sort;
        SearchBehavior* m_search;
};

#endif // COLLECTION_H
