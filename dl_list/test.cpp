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

/*
TEST_CASE("Pop back") {
  MojVektor<char> vec{'a', 'b'};
  vec.pop_back();
  CHECK(vec[0] == 'a');
  CHECK(vec.size() == 1);
  vec.pop_back();
  CHECK(vec.size() == 0);
  bool exception = false;
  try {
    vec.pop_back();
  } catch (std::out_of_range &e) {
    exception = true;
  }
  CHECK(exception);
}

TEST_CASE("Pop front") {
  MojVektor<char> vec{'a', 'b'};
  vec.pop_front();
  CHECK(vec[0] == 'b');
  CHECK(vec.size() == 1);
  vec.pop_front();
  CHECK(vec.size() == 0);
  bool exception = false;
  try {
    vec.pop_front();
  } catch (std::out_of_range &e) {
    exception = true;
  }
  CHECK(exception);
}

TEST_CASE("Metod front") {
  MojVektor<char> vec{'i', 's', 'm', 'a', 'r'};
  CHECK(vec.front() == 'i');
  bool check = false;
  MojVektor<int> vec2;
  try {
    vec2.front();
  } catch (std::out_of_range &e) {
    check = true;
  }
  CHECK(check);
}

TEST_CASE("Metod back") {
  MojVektor<char> vec{'i', 's', 'm', 'a', 'r'};
  CHECK(vec.back() == 'r');
  bool check = false;
  MojVektor<int> vec2;
  try {
    vec2.back();
  } catch (std::out_of_range &e) {
    check = true;
  }
  CHECK(check);
}

TEST_CASE("Operator == ") {
  MojVektor<char> ime1 = {'i', 's', 'm', 'a', 'r'};
  MojVektor<char> ime2 = {'i', 's', 'm', 'a', 'r'};
  MojVektor<char> ime3 = {'a', 's', 'm', 'i', 'r'};
  MojVektor<char> ime4 = {'t', 'e', 's', 't'};
  CHECK(ime1 == ime1);
  CHECK(ime1 == ime2);
  CHECK(!(ime1 == ime3));
  CHECK(!(ime1 == ime4));
}

TEST_CASE("Operator != ") {
  MojVektor<char> ime1 = {'i', 's', 'm', 'a', 'r'};
  MojVektor<char> ime2 = {'i', 's', 'm', 'a', 'r'};
  MojVektor<char> ime3 = {'a', 's', 'm', 'i', 'r'};
  MojVektor<char> ime4 = {'t', 'e', 's', 't'};
  CHECK(!(ime1 != ime1));
  CHECK(!(ime1 != ime2));
  CHECK(ime1 != ime3);
  CHECK(ime1 != ime4);
}

TEST_CASE("Full") {
  MojVektor<char> vec;
  for (auto i = 0; i < 10; vec.push_back(i++))
    ;
  CHECK(vec.size() == vec.capacity());
}

TEST_CASE("for each") {
  MojVektor<char> vec{1, 2, 3, 4, 5, 6, 7, 8};
  int i = 0;
  bool is_true = true;
  for (auto &&el : vec) {
    if (el != ++i) {
      is_true = false;
    }
  }

  CHECK(is_true);
}

TEST_CASE("Begin and end on full vector") {
  MojVektor<char> vec{'i', 's', 'm', 'a', 'r'};
  CHECK(*vec.begin() == 'i');
  CHECK(*(vec.end() - 1) == 'r');
}

TEST_CASE("BEgin and end on empty vector") {
  MojVektor<char> vec;
  CHECK(vec.begin() == vec.end());
}

TEST_CASE("Find") {
  MojVektor<char> vec{'i', 's', 'm', 'a', 'r'};
  auto it = vec.find('s');
  CHECK(*it == 's');
  it = vec.find('k');
  CHECK(it == vec.end());
}

TEST_CASE("Erase") {
  MojVektor<char> vec{'i', 's', 'm', 'a', 'r'};
  auto it = vec.erase(vec.begin() + 1);
  bool is_erased =
      vec[0] == 'i' && vec[1] == 'm' && vec[2] == 'a' && vec[3] == 'r';
  CHECK(is_erased);
  CHECK(*it == 'm');
  it = vec.erase(vec.end() - 1);
  CHECK(it == vec.end());
}

TEST_CASE("Erase interval") {
  MojVektor<char> vec{'i', 's', 'm', 'a', 'r', 'o'};
  auto it = vec.erase(vec.begin() + 1, vec.end() - 2);
  bool is_erased = vec[0] == 'i' && vec[1] == 'r' && vec[2] == 'o';
  CHECK(is_erased);
  CHECK(*it == 'r');
}

TEST_CASE("Insert") {
  MojVektor<char> vec{'i', 'm', 'a', 'r'};
  auto it = vec.insert(vec.begin() + 1, 'm');
  CHECK(vec[1] == 'm');
  CHECK(*it == 'm');
  MojVektor<char> empty;
  empty.insert(empty.begin(), 'k');
  CHECK(empty[0] == 'k');
}

TEST_CASE("Rotate") {
  MojVektor<int> vec;
  for (auto i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  vec.rotate();

  bool check = true;
  for (auto i = 0; i < 10; ++i) {
    if (vec[i] != 9 - i) {
      check = false;
    }
  }
  CHECK(check);
}

TEST_CASE("For each") {
  MojVektor<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec.for_each([](int &el) { el = el * 2; });
  bool is_true = true;
  for (int i = 0; i < 10; i++) {
    if (vec[i] != (i + 1) * 2) {
      {
        is_true = false;
      }
    }
  }
  CHECK(is_true);
}

TEST_CASE("remove if") {
  MojVektor<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec.remove_if([](int &el) { return el % 2 == 1; });
  bool is_true = true;
  for (int i = 0; i < 5; i++) {
    if (vec[i] != (i + 1) * 2) {
      {
        is_true = false;
      }
    }
  }
  CHECK(is_true);
}

TEST_CASE("fold") {
  MojVektor<int> vec{1, 2, 3, 4, 5};
  int check = vec.fold(0, [](int el, int acc) { return acc + el; });
  CHECK(check == 15);
}

*/
