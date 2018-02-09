#ifndef FLEXDEPTHSEARCH_H
#define FLEXDEPTHSEARCH_H

#include "ITR.h"

class FlexDepthSearch : public ITR
{
    public:
        FlexDepthSearch(DataGeneration &data, int d):ITR(data,d){};
        virtual ~FlexDepthSearch(){};
        void searchPrint();
        vector<Result *> searchOutput(){};
};

#endif // FLEXDEPTHSEARCH_H
