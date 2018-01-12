#ifndef RESULT_H
#define RESULT_H


class Result
{
private:
    float value;
    unsigned short info[3];
public:
    Result(double v, unsigned short varI, unsigned short cutI, unsigned short dirI, unsigned short varJ, unsigned short cutJ, unsigned short dirJ, unsigned short varK, unsigned short cutK, unsigned short dirK);
    ~Result();

};

#endif // RESULT_H
