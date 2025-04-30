#include "list.hpp"

template <typename T> void printlist(const list<T> &ls) {
  std::cout << "**********" << std::endl;
  for (auto &&el : ls) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::cout << "**********" << std::endl;
}

int main() {
  std::cout << "int list" << std::endl;
  list<int> ls{2, 3, 4, 5, 6};
  ls.push_back(999);
  ls.push_front(777);
  printlist(ls);
  ls.pop_back();
  ls.pop_front();
  printlist(ls);
  ls.pop_back();
  ls.pop_front();
  printlist(ls);
  ls.pop_back();
  ls.pop_front();
  printlist(ls);
  ls.pop_front();
  printlist(ls);
  ls.push_front(6969);
  printlist(ls);
  ls.pop_back();
  printlist(ls);
  ls.push_front(1555);
  printlist(ls);
}
