#include <iostream>
#include <set>

using namespace std;

int main(void) {
  // Default constructor
  std::set<char> t_set;
  t_set.insert('x');
  t_set.insert('y');

  std::cout << "Size of set container t_set is : " << t_set.size();

  // Move constructor
  std::set<char> t_set_new(std::move(t_set));
  std::cout << "\nSize of new set container t_set_new is : " << t_set_new.size();
  return 0;
}

//Size of set container t_set is : 2
//Size of new set container t_set_new is : 2
