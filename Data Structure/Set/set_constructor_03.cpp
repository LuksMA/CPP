// 	Copy constructor
#include <iostream>
#include <set>

using namespace std;

int main(void) {
  //Default Constructor
  std::set<int> t_set;
  t_set.insert(5);
  t_set.insert(10);

  std::cout << "Size of set container t_set is : " << t_set.size();

  // Copy constructor
  std::set<int> t_set_new(t_set);
  std::cout << "\nSize of new set container t_set_new is : " << t_set_new.size();
  return 0;
}

//Size of set container t_set is : 2
//Size of new set container t_set_new is : 2
