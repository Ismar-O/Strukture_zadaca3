#include "history.hpp"
#include <iostream>

void printProgramOptions() {
  std::cout << "Options:" << std::endl;
  std::cout << "1. Go back" << std::endl;
  std::cout << "2. Go forward" << std::endl;
  std::cout << "3. Add new page" << std::endl;
  std::cout << "4. Remove current page" << std::endl;
  std::cout << "5. Remove page using position" << std::endl;
  std::cout << "6. Print current" << std::endl;
  std::cout << "7. Print history" << std::endl;
  std::cout << "8. Quit" << std::endl;
  std::cout << "9. Print options" << std::endl;
}

int main(int argc, char *argv[]) {
  std::cout << "Zadatak 2 - Model historije preglednika" << std::endl;
  printProgramOptions();
  std::cout << std::string(60, '-') << std::endl;
  history historyModel;
  historyModel.printHistory();
  char option;
  std::cout << std::string(60, '-') << std::endl;
  while (option != '8') {

    std::cout << "Pick an option: ";
    std::cin >> option;
    std::cout << std::string(60, '-') << std::endl;
    switch (option) {
    case '1':
      if (!historyModel.goBack()) {
        std::cout << "Already at the beginning" << std::endl;
      } else {
        std::cout << "Previous page" << std::endl;
      }
      break;
    case '2':
      if (!historyModel.goForward()) {
        std::cout << "Already at the end" << std::endl;
      } else {
        std::cout << "Next page" << std::endl;
      }
      break;
    case '3':
      historyModel.addNew();
      break;
    case '4':
      if (!historyModel.removeCurrent()) {
        std::cout << "Cannot remove first page" << std::endl;
      }
      break;
    case '5':
      if (!historyModel.removeIndex()) {
        std::cout << "Cannot remove first page" << std::endl;
      }
      break;
    case '6':
      historyModel.printCurrent();
      break;
    case '7':
      historyModel.printHistory();
      break;
    case '8':
      std::cout << "Closing..." << std::endl;
      break;
    case '9':
      printProgramOptions();
      break;
    default:
      std::cout << "Option is not valid" << std::endl;
      std::cin.ignore(100, '\n');
      break;
    }

    std::cout << std::string(60, '-') << std::endl;
  }
}
