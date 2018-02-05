#ifndef ICOMPARATOR_H
#define ICOMPARATOR_H


class IComparator
{
    public:
        virtual bool compare(int a, int b) = 0;
        virtual ~IComparator(){};
};

#endif // ICOMPARATOR_H
