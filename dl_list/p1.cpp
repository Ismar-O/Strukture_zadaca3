#include <iostream>
#include <list>

int main() {
  std::list<int> ls{1, 2, 3, 4, 5};
  for (auto &&el : ls) {
    std::cout << el << std::endl;
  }

  ls.insert(ls.end(), 999);

  for (auto &&el : ls) {
    std::cout << el << std::endl;
  }
}
