#include <iostream>
#include <map>

class Obj {
public:
    Obj() {}
    Obj(int x, int y) : x(x), y(y) {}
    int x;
    int y;
   };


int main (int argc, char ** argv) {

    std::map<std::string, Obj> catalog;
    catalog.insert(std::map<std::string, Obj>::value_type("test", Obj(1,2)));

    std::cout << catalog["test"].x << " " << catalog["test"].y << std::endl;

    return 0;
}
