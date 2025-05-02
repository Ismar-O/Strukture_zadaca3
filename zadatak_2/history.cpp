#include "history.hpp"
bool history::goBack() {
  if (current_ == data_.begin())
    return 0;
  current_--;
  return 1;
}
bool history::goForward() {
  if (current_ == --data_.end())
    return 0;
  current_++;
  return 1;
}

bool history::addNew() {
  std::cout << "Input the value ";
  std::string nova;
  std::cin >> nova;
  auto temp = current_;
  data_.erase(++temp, data_.end());
  data_.push_back(nova);
  current_++;
  std::cout << "Value: " << nova << " added!" << std::endl;
  return 1;
}

bool history::removeCurrent() {
  if (current_ == data_.begin()) {
    return 0;
  }
  auto temp = current_--;
  data_.erase(temp);
  return 1;
}

bool history::removeIndex() {
  size_t index;
  std::cout << "Positon ";
  std::cin >> index;
  if (index >= data_.size()) {
    throw std::out_of_range{"Index out of range"};
  }
  if (!index) {
    return 0;
  }
  auto it = data_.begin();
  for (size_t i = 0; i < index; i++) {
    it++;
  }
  if (it == current_) {
    current_--;
  }
  data_.erase(it);
  return 1;
}

bool history::printCurrent() {
  std::cout << "Current " << *current_;
  int br = 0;
  for (auto it = data_.begin(); it != current_; it++) {
    br++;
  }
  std::cout << "(" << br << ")" << std::endl;
  return 1;
}

bool history::printHistory() {
  std::cout << "History" << std::endl;
  auto it = data_.begin();
  int br = 0;
  while (it != data_.end()) {
    std::cout << *it << " (" << br << ")";
    it++;
    if (it != data_.end()) {
      std::cout << "-->";
    }
    br++;
  }
  std::cout << std::endl;
  return 1;
}
