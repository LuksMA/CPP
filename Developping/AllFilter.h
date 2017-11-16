#ifndef ALLFILTER_H
#define ALLFILTER_H

#include "Filter.h"

class AllFilter : public Filter
{   vector<Filter *> criterias;

    public:
        void addFilter(Filter &A);
        void clearAllFilter();
};

#endif // ALLFILTER_H
