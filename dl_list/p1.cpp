#include <iostream>
#include <list>

int main() {
  std::list<int> ls{1, 2, 3, 4, 5};
  for (auto &&el : ls) {
    std::cout << el << std::endl;
  }
  std::list<int> k{1};
  ls.erase(ls.end());

  for (auto &&el : ls) {
    std::cout << el << std::endl;
  }
}
