#ifndef RES_H
#define RES_H

#include <vector>
using namespace std;

class Res
{
    public:
        Res(double res, vector<int> ind, int dir);
        virtual ~Res();
    private:
        float result;
        vector<int>* index; // variable combinations
        int direction; // range = 0 to 2^depth-1
};

#endif // RES_H
