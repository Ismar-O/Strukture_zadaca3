#pragma once
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
class history {
public:
  history() : data_{"Homepage"}, current_(data_.begin()) {}

  bool goBack();
  bool goForward();
  bool addNew();
  bool removeCurrent();
  bool removeIndex();
  bool printCurrent();
  bool printHistory();

private:
  std::list<std::string> data_;
  std::list<std::string>::iterator current_;
};
