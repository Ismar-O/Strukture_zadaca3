#pragma once
#include <initializer_list>
#include <iostream>
#include <iterator>

template <typename T> struct ListTestAccess;

template <typename T> class list {
public:
  list() = default;

  list(std::initializer_list<T> ls) {
    size_ = 0;
    for (auto it = ls.begin(); it != ls.end(); it++) {
      push_back(*it);
    }
  }

  list(list &other) {
    auto temp = other.head_;
    while (temp != nullptr) {
      push_back(temp->value_);
      temp = temp->next_;
    }
  }

  list(list &&other)
      : head_{other.head_}, tail_{other.tail_}, size_{other.size_} {
    other.tail_ = other.head_ = 0;
    other.size_ = 0;
  }
  // MOZDA BOLJE OVA IMPLEMENTACIJA
  //
  // list(list &&other){
  // std::swap(head_, other.head_);
  // std::swap(tail_, other.tail_);
  // std::swap(size_, other.size_)
  // }
  //

  list &operator=(list &other) {
    if (this == &other) {
      return *this;
    }
    clear();
    auto temp = other.head_;
    while (temp != nullptr) {
      push_back(temp->value_);
      temp = temp->next_;
    }
    return *this;
  }

  list &operator=(list &&other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
    return *this;
  }

  ~list() { clear(); }

  template <typename U> void push_back(U &&element) {
    auto newNode = new node(std::forward<U>(element));
    size_++;
    if (head_ == nullptr) {

      tail_ = head_ = newNode;
      return;
    }

    newNode->previous_ = tail_;
    tail_->next_ = newNode;
    tail_ = newNode;
  }

  template <typename U> void push_front(U &&element) {
    auto newNode = new node(std::forward<U>(element));
    size_++;
    if (head_ == nullptr) {
      tail_ = head_ = newNode;
      return;
    }
    newNode->next_ = head_;
    head_->previous_ = newNode;
    head_ = newNode;
  }

  class Iterator;
  Iterator begin() const { return Iterator(head_); }
  Iterator end() const { return Iterator(nullptr); }

  template <typename U> void insert(Iterator position, U &&element) {
    auto newNode = new node(std::forward<U>(element));
    if (head_ == nullptr) {
      tail_ = head_ = newNode;
      size_++;
      return;
    } else if (position == nullptr) {
      push_back(element);
      return;
    } else if (position == head_) {
      push_front(element);
      return;
    }

    size_++;

    auto oldPrevious = position.p_->previous_;
    newNode->next_ = position.p_;
    position.p_->previous_ = newNode;
    oldPrevious->next_ = newNode;
    newNode->previous_ = oldPrevious;
  }

  bool empty() { return size_ == 0; }
  size_t size() { return size_; }
  T front() { return head_->value_; }
  T back() { return tail_->value_; }

  void clear() {
    while (head_ != nullptr) {
      auto temp = head_->next_;
      delete head_;
      head_ = temp;
    }
    tail_ = nullptr;
    size_ = 0;
  }

  void pop_front() {
    if (size_ == 0) {
      return;
    }
    auto temp = head_;
    head_ = head_->next_;
    delete temp;
    size_--;
    if (head_ == nullptr) {
      tail_ = nullptr;
      return;
    }
    head_->previous_ = nullptr;
  }

  void pop_back() {
    if (size_ == 0) {
      return;
    }
    auto temp = tail_;

    tail_ = tail_->previous_;
    delete temp;
    size_--;

    if (tail_ == nullptr) {
      head_ = nullptr;
      return;
    }
    tail_->next_ = nullptr;
  }

  void erase(Iterator position) {

    if (size_ == 0)
      return;
    if (position == head_) {
      pop_front();
      return;
    }
    if (position == tail_) {
      pop_back();
      return;
    }
    position->previous_->next_ = position->next_;
    position->next_->previous_ = position->previous_;
    delete position;
    size_--;
  }

  // TODO VRATITI NODE U PRIVATE TODO
  class node {
  public:
    node(const T &element) : value_{element} {}
    node(T &&element) : value_{std::move(element)} {}

    T value_;
    node *next_ = nullptr;
    node *previous_ = nullptr;
  };

  class Iterator {
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using difference_type = long int;

    Iterator(node *p) : p_{p} {}
    Iterator &operator++() {
      if (p_)
        p_ = p_->next_;
      return *this;
    }

    friend list<T>;

    Iterator operator++(int) {
      auto r = *this;
      if (p_)
        p_ = p_->next_;
      return r;
    }
    Iterator &operator--() {
      if (p_)
        p_ = p_->previous_;
      return *this;
    }

    Iterator operator--(int) {
      auto r = *this;
      if (p_)
        p_ = p_->previous_;
      return r;
    }
    bool operator==(const Iterator &other) { return p_ == other.p_; }
    bool operator!=(const Iterator &other) { return p_ != other.p_; }
    T &operator*() { return p_->value_; }
    T *operator->() { return &p_->value_; }

  private:
    node *p_;
  };

  friend struct ListTestAccess<T>;

private:
  node *head_ = nullptr;
  node *tail_ = nullptr;
  size_t size_ = 0;
};

template <typename T> struct ListTestAccess {
  static typename list<T>::node *getHead(const list<T> &list) {
    return list.head_;
  }
  static typename list<T>::node *getTail(const list<T> &list) {
    return list.tail_;
  }
};
