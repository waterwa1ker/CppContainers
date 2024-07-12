#ifndef CPP2_S21_CONTAINERS_1_LIST_LIST_CC_
#define CPP2_S21_CONTAINERS_1_LIST_LIST_CC_
#include "./list.h"

template <class T>
struct s21::list<T>::node {
  value_type value_;
  node *next_;
  node *prev_;
  node() : next_(nullptr), prev_(nullptr) {}
  node(node *now) : next_(nullptr), prev_(now) {}
};

template <typename T>
s21::list<T>::list() {
  node_head_ = new node;
  node_tail_ = nullptr;
  size_ = 0;
}

template <typename T>
s21::list<T>::list(size_type n) {
  node_head_ = new node;
  size_ = n;

  node *tmp = node_head_->next_;
  for (size_type i = 0; i < n; ++i) {
    tmp->next_ = new node(tmp);
    node_tail_ = tmp;
    tmp = tmp->next_;
  }
}

template <class T>
s21::list<T>::list(const std::initializer_list<T> &items) : list(items.size()) {
  // std::copy(items.begin(), items.end(), )
}

template <typename T>
s21::list<T>::~list() {
  std::cout << "hello";  // add in new versions)
}

// template <typename T>
// bool s21::list<T>::empty() {
//   return size_ == 0;  // add in new version
// }

// template <typename T>
// s21::list<T>::size_type s21::list<T>::size() {
//   return size_;
// }

template <class T>
s21::list<T>::node *s21::list<T>::getHead() {
  return this->node_head_;
}

template <typename T>
s21::list<T>::ListIterator::ListIterator() {
  ptr_node_ = this->getNode();
}

template <typename T>
s21::list<T>::ListIterator::~ListIterator() {
  ptr_node_ = nullptr;
}

template <class T>
T s21::list<T>::ListIterator::operator*() {
  return ptr_node_->value_;
}

template <typename T>
s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator++() {
  // проверить как ведёт себя если это конечная нода
  ptr_node_ = ptr_node_->next_;
  return *this;
}

template <typename T>
s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator--() {
  // проверить как ведёт себя если это конечная нода
}

template <typename T>
s21::list<T>::node *s21::list<T>::ListIterator::getNode() {
  return ptr_node_;
}

template <typename T>
bool s21::list<T>::ListIterator::operator==(
    const s21::list<T>::ListIterator &iter) const {
  return this->ptr_node_ == iter.ptr_node_;
}

template <class T>
bool s21::list<T>::ListIterator::operator!=(
    const s21::list<T>::ListIterator &iter) const {
  return this->ptr_node_ != iter.ptr_node_;
}

#endif /** CPP2_S21_CONTAINERS_1_LIST_LIST_CC_ */