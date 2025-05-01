#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "list.hpp"

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
  list<char> initCtor{'A', 'B', 'C'};
  list<char>::Iterator it = initCtor.begin();
  bool is_true =
      *(it++) == 'A' && *(it++) == 'B' && *it == 'C' && initCtor.size() == 3;
  CHECK(is_true);
}

TEST_CASE("List one element head/tail check") {

  list<char> list{'a'};
  bool is_true = list.size() == 1;
  CHECK(is_true);
  auto head_ = ListTestAccess<char>::getHead(list);
  auto tail_ = ListTestAccess<char>::getTail(list);
  CHECK(tail_ == head_);
}

TEST_CASE("Copy constructor") {
  list<char> def{'A', 'B', 'C'};
  list<char> copyCtor(def);
  list<char>::Iterator it = copyCtor.begin();

  bool is_true =
      *(it++) == 'A' && *(it++) == 'B' && *it == 'C' && copyCtor.size() == 3;
  CHECK(is_true);
}

TEST_CASE("Copy operator") {
  list<char> def{'A', 'B', 'C'};
  list<char> copyCtor = def;
  list<char>::Iterator it = copyCtor.begin();

  bool is_true =
      *(it++) == 'A' && *(it++) == 'B' && *it == 'C' && copyCtor.size() == 3;
  CHECK(is_true);
}

TEST_CASE("Copy operator same element") {
  list<char> l1{'a'};
  l1 = l1;
  CHECK(l1.front() == 'a');
}

TEST_CASE("Move constuctor") {
  list<char> l1{'a'};
  auto it = l1.begin();
  list<char> l2{std::move(l1)};
  CHECK(it == l2.begin());
}

TEST_CASE("Move operator") {
  list<char> l1{'a'};
  auto it = l1.begin();
  list<char> l2;
  l2 = std::move(l1);
  CHECK(it == l2.begin());
}

TEST_CASE("Push back empty list") {
  list<char> list;
  char a = 'a';
  list.push_back(a);
  CHECK(list.front() == 'a');
}

TEST_CASE("Push back one element list") {
  list<char> list{'a'};
  char a = 'b';
  list.push_back(a);
  CHECK(list.front() == 'a');
  CHECK(list.back() == 'b');
  CHECK(list.size() == 2);
}

TEST_CASE("Push back list") {
  list<char> list{'i', 's', 'm', 'a'};
  char a = 'r';
  list.push_back(a);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}
TEST_CASE("Push back list move") {
  list<char> list{'i', 's', 'm', 'a'};
  list.push_back('r');
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}

TEST_CASE("Push front empty list") {
  list<char> list;
  list.push_front('a');
  CHECK(list.front() == 'a');
}

TEST_CASE("Push front one element list") {
  list<char> list{'a'};
  char a = 'b';
  list.push_front(a);
  CHECK(list.front() == 'b');
  CHECK(list.back() == 'a');
  CHECK(list.size() == 2);
}

TEST_CASE("Push front") {
  list<char> list{'s', 'm', 'a', 'r'};
  char a = 'i';
  list.push_front(a);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}

TEST_CASE("Push front MOVE") {
  list<char> list{'s', 'm', 'a', 'r'};
  list.push_front('i');
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}

TEST_CASE("Insert on begin empty list") {
  list<char> list;
  list.insert(list.begin(), 'a');
  CHECK(list.front() == 'a');
}

TEST_CASE("Insert on begin one element list") {
  list<char> list{'a'};
  list.insert(list.begin(), 'b');
  CHECK(list.front() == 'b');
  CHECK(list.back() == 'a');
  CHECK(list.size() == 2);
}

TEST_CASE("Insert on end empty list") {
  list<char> list;
  list.insert(list.end(), 'a');
  CHECK(list.front() == 'a');
}

TEST_CASE("Insert on last element one element list") {
  list<char> list{'a'};
  list.insert(list.end(), 'c');
  CHECK(list.front() == 'a');
  CHECK(list.back() == 'c');
  CHECK(list.size() == 2);
}

TEST_CASE("Insert on begin + 2") {
  list<char> list{'i', 's', 'a', 'r'};
  auto toInsert = list.begin();
  toInsert++;
  toInsert++;
  list.insert(toInsert, 'm');
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}

TEST_CASE("Size") {
  list<int> list{1, 2, 3};
  bool is_true = true;
  for (auto i = 4; i < 1000; ++i) {
    list.push_back(i);
    if (list.size() != i) {
      is_true = false;
      break;
    }
  }
  CHECK(is_true);
}

TEST_CASE("Empty") {
  list<char> list;
  CHECK(list.size() == 0);
}

TEST_CASE("Pop back empty") {
  list<char> ls;
  ls.pop_back();
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);

  CHECK(ls.size() == 0);
}

TEST_CASE("Pop back one element") {
  list<char> ls{'a'};
  ls.pop_back();
  CHECK(ls.size() == 0);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
}

TEST_CASE("Pop back") {
  list<char> list{'i', 's', 'm', 'a', 'r', 'x'};
  list.pop_back();
  auto it = list.begin();
  std::cout << std::endl;
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
  CHECK(list.size() == 5);
}

TEST_CASE("Pop front empty") {
  list<char> ls;
  ls.pop_front();
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);

  CHECK(ls.size() == 0);
}

TEST_CASE("Pop front one element") {
  list<char> ls{'a'};
  ls.pop_front();
  CHECK(ls.size() == 0);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
}

TEST_CASE("Pop front") {
  list<char> list{'x', 'i', 's', 'm', 'a', 'r'};
  list.pop_front();
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}

TEST_CASE("Erase one element begin") {
  list<char> ls{'a'};
  ls.erase(ls.begin());
  CHECK(ls.size() == 0);
  auto head_ = ListTestAccess<char>::getHead(ls);
  auto tail_ = ListTestAccess<char>::getTail(ls);
  CHECK(tail_ == nullptr);
  CHECK(head_ == nullptr);
}

TEST_CASE("Erase") {
  list<char> list{'i', 's', 'm', 'X', 'a', 'r'};
  auto toErase = list.begin();
  toErase++;
  toErase++;
  toErase++;
  list.erase(toErase);
  auto it = list.begin();
  bool is_true = *(it++) == 'i' && *(it++) == 's' && *(it++) == 'm' &&
                 *(it++) == 'a' && *(it++) == 'r';
  CHECK(is_true);
}

TEST_CASE("Reverse") {
  list<int> ls;
  for (auto i = 0; i < 10; i++) {
    ls.push_back(i);
  }
  ls.reverse();
  bool check = true;
  auto it = ls.begin();
  for (auto i = 0; i < 10; ++i) {
    if (*(it++) != 9 - i) {
      check = false;
    }
  }
  CHECK(check);
}

TEST_CASE("remove if") {
  list<int> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list.remove_if([](int &el) { return el % 2 == 1; });
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
}

TEST_CASE("Split front") {
  list<int> ls1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = ls1.begin();
  it++;
  it++;
  it++;
  // it pokazuje na 4;
  auto ls2 = ls1.split_front(it);
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
}

TEST_CASE("Split front iterator on first el") {
  list<int> ls1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = ls1.begin();
  // it pokazuje na 1;
  auto ls2 = ls1.split_front(it);
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
}
