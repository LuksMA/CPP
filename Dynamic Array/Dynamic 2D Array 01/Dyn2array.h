#ifndef DYN2ARRAY_H
#define DYN2ARRAY_H


class Dyn2array
{
private:
    int** var;
    int rowL;
    int columnL;


public:
    Dyn2array(int row, int column);
    ~Dyn2array();
    int getRow(){ return rowL;};
    int getColumn(){ return columnL;};
    int** getArray(){ return var;};

    class Proxy {
    public:
        Proxy(int* _array) : _array(_array) { }

        int operator[](int index) {
            return _array[index];
        }

    private:
        int* _array;
    };

    Proxy operator[](int index) {
        return Proxy(var[index]);
    }



};

#endif // DYN2ARRAY_H
