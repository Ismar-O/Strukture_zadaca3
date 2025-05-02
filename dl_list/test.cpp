#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list.hpp"

// Pomocna funkcija za ipis liste
template <typename T> void printList(list<T> &ls) {
  std::cout << "List -> ";
  for (auto &&el : ls) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  // std::cout << "*******" << std::endl;
}

std::string devider(20, '-');

TEST_CASE("Default constructor") {
  list<char> list;
  bool is_true = list.size() == 0;
  CHECK(is_true);
  auto head_ = ListTestAccess<char>::getHead(list);
  auto tail_ = ListTestAccess<char>::getTail(list);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
}
TEST_CASE("Init list constructor") {
  std::cout << "initializer list ctor" << std::endl;
  list<char> initCtor{'A', 'B', 'C'};
  printList(initCtor);
  list<char>::Iterator it = initCtor.begin();
  bool is_true =
      *(it++) == 'A' && *(it++) == 'B' && *it == 'C' && initCtor.size() == 3;
  CHECK(is_true);

  std::cout << devider << std::endl;
}

TEST_CASE("List one element head/tail check") {

  std::cout << "One element list" << std::endl;
  list<char> list{'a'};
  printList(list);
  bool is_true = list.size() == 1;
  CHECK(is_true);
  auto head_ = ListTestAccess<char>::getHead(list);
  auto tail_ = ListTestAccess<char>::getTail(list);
  CHECK(tail_ == head_);
  std::cout << devider << std::endl;
}

TEST_CASE("Copy constructor") {

  std::cout << "Copy ctor" << std::endl;
  list<char> def{'A', 'B', 'C'};
  list<char> copyCtor(def);
  printList(copyCtor);
  list<char>::Iterator it = copyCtor.begin();

  bool is_true =
      *(it++) == 'A' && *(it++) == 'B' && *it == 'C' && copyCtor.size() == 3;
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Copy operator") {
  std::cout << "Copy operator" << std::endl;
  list<char> def{'A', 'B', 'C'};
  list<char> copyCtor = def;
  printList(copyCtor);
  list<char>::Iterator it = copyCtor.begin();

  bool is_true =
      *(it++) == 'A' && *(it++) == 'B' && *it == 'C' && copyCtor.size() == 3;
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Copy operator same element") {

  std::cout << "Copy operator same element" << std::endl;
  list<char> l1{'a'};
  l1 = l1;
  printList(l1);
  CHECK(l1.front() == 'a');
  std::cout << devider << std::endl;
}

TEST_CASE("Move constuctor") {
  std::cout << "Move ctor" << std::endl;
  list<char> l1{'a'};
  printList(l1);
  auto it = l1.begin();
  list<char> l2{std::move(l1)};
  printList(l2);
  CHECK(it == l2.begin());
  std::cout << devider << std::endl;
}

TEST_CASE("Move operator") {
  std::cout << "Move operator" << std::endl;
  list<char> l1{'a'};
  printList(l1);
  auto it = l1.begin();
  list<char> l2;
  l2 = std::move(l1);
  printList(l2);
  CHECK(it == l2.begin());
  std::cout << devider << std::endl;
}

TEST_CASE("Push back empty list") {

  std::cout << "Push back empty list" << std::endl;
  list<char> list;
  printList(list);
  char a = 'a';
  std::cout << "Pushing 'a'" << std::endl;
  list.push_back(a);
  printList(list);
  CHECK(list.front() == 'a');
  std::cout << devider << std::endl;
}

TEST_CASE("Push back one element list") {

  std::cout << "Push back one element list" << std::endl;
  list<char> list{'a'};
  printList(list);
  char a = 'b';
  std::cout << "Pushing 'b'" << std::endl;
  list.push_back(a);
  printList(list);
  CHECK(list.front() == 'a');
  CHECK(list.back() == 'b');
  CHECK(list.size() == 2);
  std::cout << devider << std::endl;
}

TEST_CASE("Push back list") {

  std::cout << "Push back" << std::endl;
  list<char> list{'i', 's', 'm', 'a'};
  printList(list);
  std::cout << "Pushing back 'r'" << std::endl;
  char a = 'r';
  list.push_back(a);
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}
TEST_CASE("Push back list move") {
  std::cout << "Push back - move" << std::endl;
  list<char> list{'i', 's', 'm', 'a'};
  printList(list);
  std::cout << "Pushing back 'r' - rvalue" << std::endl;
  list.push_back('r');
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Push front empty list") {
  std::cout << "Push front empty list" << std::endl;
  list<char> list;
  printList(list);
  std::cout << "Pushing front 'a'" << std::endl;
  list.push_front('a');
  printList(list);
  CHECK(list.front() == 'a');
  std::cout << devider << std::endl;
}

TEST_CASE("Push front one element list") {
  std::cout << "Push front one element list" << std::endl;
  list<char> list{'a'};
  printList(list);
  char a = 'b';
  std::cout << "Pushing front 'b'" << std::endl;
  list.push_front(a);
  printList(list);
  CHECK(list.front() == 'b');
  CHECK(list.back() == 'a');
  CHECK(list.size() == 2);
  std::cout << devider << std::endl;
}

TEST_CASE("Push front") {
  std::cout << "Push front" << std::endl;
  list<char> list{'s', 'm', 'a', 'r'};
  printList(list);
  char a = 'i';
  std::cout << "Pushing front 'i'" << std::endl;
  list.push_front(a);
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Push front MOVE") {
  std::cout << "Push front - move" << std::endl;
  list<char> list{'s', 'm', 'a', 'r'};
  printList(list);
  list.push_front('i');
  std::cout << "Pushing front 'i' - rvalue" << std::endl;
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Insert on begin empty list") {
  std::cout << "Insert on begin empty list" << std::endl;
  list<char> list;
  printList(list);
  std::cout << "Inserting 'a' on begin" << std::endl;
  list.insert(list.begin(), 'a');
  printList(list);
  CHECK(list.front() == 'a');
  std::cout << devider << std::endl;
}

TEST_CASE("Insert on begin one element list") {
  std::cout << "Insert on begin one element list" << std::endl;
  list<char> list{'a'};
  printList(list);
  std::cout << "Inserting 'b' on begin" << std::endl;
  list.insert(list.begin(), 'b');
  printList(list);
  CHECK(list.front() == 'b');
  CHECK(list.back() == 'a');
  CHECK(list.size() == 2);
  std::cout << devider << std::endl;
}

TEST_CASE("Insert on end empty list") {
  std::cout << "Insert on end empty list" << std::endl;
  list<char> list;
  printList(list);
  std::cout << "Inserting 'a' on end" << std::endl;
  list.insert(list.end(), 'a');
  printList(list);
  CHECK(list.front() == 'a');
  std::cout << devider << std::endl;
}

TEST_CASE("Insert on last element one element list") {
  std::cout << "Insert on last element one element list" << std::endl;
  list<char> list{'a'};
  printList(list);
  std::cout << "Inserting 'c' on end" << std::endl;
  list.insert(list.end(), 'c');
  printList(list);
  CHECK(list.front() == 'a');
  CHECK(list.back() == 'c');
  CHECK(list.size() == 2);
  std::cout << devider << std::endl;
}

TEST_CASE("Insert on begin + 2") {
  std::cout << "Insert in the middle" << std::endl;
  list<char> list{'i', 's', 'a', 'r'};
  printList(list);
  auto toInsert = list.begin();
  toInsert++;
  toInsert++;
  std::cout << "Inserting 'm' on begin + 2" << std::endl;
  list.insert(toInsert, 'm');
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Size") {
  std::cout << "Size" << std::endl;
  list<int> list{1, 2, 3};
  bool is_true = true;
  for (auto i = 4; i < 1000; ++i) {
    list.push_back(i);
    if (list.size() != i) {
      is_true = false;
      break;
    }
  }
  printList(list);
  std::cout << "Size = " << list.size() << std::endl;
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Empty") {
  std::cout << "Empty" << std::endl;
  list<char> list;
  printList(list);
  std::cout << "Empty? : " << list.empty() << std::endl;
  CHECK(list.size() == 0);
  list.push_back(65);
  printList(list);
  std::cout << "Empty? : " << list.empty() << std::endl;
  std::cout << devider << std::endl;
}

TEST_CASE("Pop back empty") {
  std::cout << "Pop back on empty list" << std::endl;
  list<char> ls;
  printList(ls);
  std::cout << "Poping back on empty list" << std::endl;
  ls.pop_back();
  printList(ls);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);

  CHECK(ls.size() == 0);
  std::cout << devider << std::endl;
}

TEST_CASE("Pop back one element") {
  std::cout << "Pop back on one element list" << std::endl;
  list<char> ls{'a'};
  printList(ls);
  std::cout << "Poping back" << std::endl;
  ls.pop_back();
  printList(ls);
  CHECK(ls.size() == 0);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
  std::cout << devider << std::endl;
}

TEST_CASE("Pop back") {
  std::cout << "Pop back" << std::endl;
  list<char> list{'i', 's', 'm', 'a', 'r', 'x'};
  printList(list);
  std::cout << "Poping back" << std::endl;
  list.pop_back();
  printList(list);
  auto it = list.begin();
  std::cout << std::endl;
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  CHECK(list.size() == 5);
  std::cout << devider << std::endl;
}

TEST_CASE("Pop front empty") {
  std::cout << "Pop front on empty list" << std::endl;
  list<char> ls;
  printList(ls);
  std::cout << "Poping front" << std::endl;
  ls.pop_front();
  printList(ls);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);

  CHECK(ls.size() == 0);
  std::cout << devider << std::endl;
}

TEST_CASE("Pop front one element") {
  std::cout << "Pop front on one element list" << std::endl;
  list<char> ls{'a'};
  printList(ls);
  std::cout << "Poping front" << std::endl;
  ls.pop_front();
  printList(ls);
  CHECK(ls.size() == 0);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
  std::cout << devider << std::endl;
}

TEST_CASE("Pop front") {
  std::cout << "Pop front" << std::endl;
  list<char> list{'x', 'i', 's', 'm', 'a', 'r'};
  printList(list);
  std::cout << "Poping front" << std::endl;
  list.pop_front();
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Erase one element begin") {
  std::cout << "Erase one element on begin" << std::endl;
  list<char> ls{'a'};
  printList(ls);
  std::cout << "Erasing on begining" << std::endl;
  ls.erase(ls.begin());
  printList(ls);
  CHECK(ls.size() == 0);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
  std::cout << devider << std::endl;
}

TEST_CASE("Erase") {
  std::cout << "Erase" << std::endl;
  list<char> list{'i', 's', 'm', 'X', 'a', 'r'};
  printList(list);
  auto toErase = list.begin();
  toErase++;
  toErase++;
  toErase++;
  std::cout << "Erasing X" << std::endl;
  list.erase(toErase);
  printList(list);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Reverse empty") {
  std::cout << "Reverse empty" << std::endl;
  list<char> ls;
  printList(ls);
  ls.reverse();
  printList(ls);

  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
  std::cout << devider << std::endl;
}

TEST_CASE("Reverse one element") {
  std::cout << "Reverse one element" << std::endl;
  list<int> ls{999};
  printList(ls);
  ls.reverse();
  printList(ls);
  bool check = true;
  auto it = ls.begin();
  CHECK(*it == 999);

  auto head_ = ListTestAccess<int>::getHead(ls);
  auto tail_ = ListTestAccess<int>::getTail(ls);
  CHECK(tail_->next_ == nullptr);
  CHECK(head_->previous_ == nullptr);
  CHECK(tail_->previous_ == nullptr);
  CHECK(head_->next_ == nullptr);
  std::cout << devider << std::endl;
}

TEST_CASE("Reverse") {
  std::cout << "Reverse" << std::endl;
  list<int> ls;
  for (auto i = 0; i < 10; i++) {
    ls.push_back(i);
  }
  printList(ls);
  ls.reverse();
  printList(ls);
  bool check = true;
  auto it = ls.begin();
  for (auto i = 0; i < 10; ++i) {
    if (*(it++) != 9 - i) {
      check = false;
    }
  }
  CHECK(check);
  std::cout << devider << std::endl;
}

TEST_CASE("remove if") {
  std::cout << "Remove if" << std::endl;
  list<int> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printList(list);
  std::cout << "Removing odd numbers" << std::endl;
  list.remove_if([](int &el) { return el % 2 == 1; });
  printList(list);
  bool is_true = true;
  auto it = list.begin();
  for (int i = 0; i < 5; i++) {
    if (*(it++) != (i + 1) * 2) {
      {
        is_true = false;
      }
    }
  }
  CHECK(is_true);
  std::cout << devider << std::endl;
}

TEST_CASE("Split front") {
  std::cout << "Split front" << std::endl;
  list<int> ls1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Original list" << std::endl;
  printList(ls1);
  auto it = ls1.begin();
  it++;
  it++;
  it++;
  // it pokazuje na 4;
  std::cout << "Splitin on 4" << std::endl;
  auto ls2 = ls1.split_front(it);
  std::cout << "Front:" << std::endl;
  printList(ls2);
  std::cout << "Original:" << std::endl;
  printList(ls1);

  bool check1 = true;
  auto it1 = ls1.begin();
  for (int i = 4; i < 11; i++) {
    if (*(it1++) != i) {
      check1 = false;
    }
  }
  CHECK(check1);

  bool check2 = true;
  auto it2 = ls2.begin();
  for (int i = 1; i < 4; i++) {
    if (*(it2++) != i) {
      check2 = false;
    }
  }
  CHECK(check2);

  CHECK(ls1.size() == 7);
  CHECK(ls2.size() == 3);
  auto head_1 = ListTestAccess<int>::getHead(ls1);
  auto tail_1 = ListTestAccess<int>::getTail(ls1);
  CHECK(tail_1->next_ == nullptr);
  CHECK(head_1->previous_ == nullptr);

  auto head_2 = ListTestAccess<int>::getHead(ls2);
  auto tail_2 = ListTestAccess<int>::getTail(ls2);
  CHECK(tail_2->next_ == nullptr);
  CHECK(head_2->previous_ == nullptr);
  std::cout << devider << std::endl;
}

TEST_CASE("Split front iterator on first el") {
  std::cout << "Split font on first element" << std::endl;
  list<int> ls1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Original list" << std::endl;
  printList(ls1);
  auto it = ls1.begin();
  // it pokazuje na 1;
  std::cout << "Spliting on 1" << std::endl;
  auto ls2 = ls1.split_front(it);

  std::cout << "Front:" << std::endl;
  printList(ls2);
  std::cout << "Original:" << std::endl;
  printList(ls1);

  bool check1 = true;
  auto it1 = ls1.begin();
  for (int i = 1; i < 11; i++) {
    if (*(it1++) != i) {
      check1 = false;
    }
  }
  CHECK(check1);

  CHECK(ls1.size() == 10);
  CHECK(ls2.size() == 0);

  auto head_1 = ListTestAccess<int>::getHead(ls1);
  auto tail_1 = ListTestAccess<int>::getTail(ls1);

  CHECK(tail_1->next_ == nullptr);
  CHECK(head_1->previous_ == nullptr);

  auto head_2 = ListTestAccess<int>::getHead(ls2);
  auto tail_2 = ListTestAccess<int>::getTail(ls2);
  CHECK(tail_2 == nullptr);
  CHECK(head_2 == nullptr);
  std::cout << devider << std::endl;
}
