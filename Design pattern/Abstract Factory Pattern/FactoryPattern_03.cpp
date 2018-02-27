// C++ program to demonstrate factory method design pattern
#include <iostream>
#include <vector>

using namespace std;

enum DataType {
    continuous,    ordinal,    nominal
};

/// Step 1. Create an interface.
class Data {
public:
    virtual void printData() = 0;
    static Data* Create(DataType type);
};

class ContVar : public Data {
public:
    void printData() {
        cout << "This is a continuous variable." << endl;
    }
};

class OrdVar : public Data {
public:
    void printData() {
        cout << "This is an ordinal variable." << endl;
    }
};

class NomVar : public Data {
public:
    void printData() {
        cout << "This is a nominal variable." << endl;
    }
};

/// Step 3. Create a Factory to generate object of concrete class based on given information
Data* Data::Create(DataType type) {
    if (type == continuous)
        return new ContVar();
    else if (type == ordinal)
        return new OrdVar();
    else if (type == nominal)
        return new NomVar();
    else return NULL;
}


/// Step 4. Use the Factory to get object of concrete class by passing an information such as type.
class Client {
public:
    Client(DataType Input)
    {
        DataType type = Input;
        pData = Data::Create(type);
    }
    ~Client() {
        if (pData) {
            delete[] pData;
            pData = NULL;
        }
    }
    Data* getData()  {
        return pData;
    }

private:
    Data *pData;
};



int main(){
    Client *pClient0 = new Client(continuous);
    Client *pClient1 = new Client(ordinal);
    Client *pClient2 = new Client(nominal);

    vector<Data *> dataSet;
    dataSet.push_back(pClient0->getData());
    dataSet.push_back(pClient1->getData());
    dataSet.push_back(pClient2->getData());

    for(int i=0; i<3; ++i){
        dataSet[i] ->printData();
    }


    return 0;
}
