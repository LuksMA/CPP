#include <iostream>
#include <set>

using namespace std;

int main(void) {
  // Default constructor
  std::set<char> t_set;

  t_set.insert('a');
  t_set.insert('e');
  t_set.insert('i');
  t_set.insert('o');
  t_set.insert('u');

  int size = t_set.size();

  std::cout << "Contents of set container t_set = " << size;
  return 0;
}

//Contents of set container t_set = 5
