#ifndef CPP2_S21_CONTAINERS_1_LIST_LIST_CC_
#define CPP2_S21_CONTAINERS_1_LIST_LIST_CC_
#include "./list.h"

// Определение структуры

template <class T>
struct s21::list<T>::node {
  value_type value_;
  node *next_;
  node *prev_;
  node() : next_(nullptr), prev_(nullptr) {}
  node(node *now) : next_(nullptr), prev_(now) {}
};

// Конструкторы

template <typename T>
s21::list<T>::list() {
  node_head_ = nullptr;
  node_tail_ = nullptr;
  size_ = 0;
}

template <typename T>
s21::list<T>::list(size_type n) {
  node_head_ = new node;
  node_head_->value_ = 0;
  size_ = n;

  node *tmp = node_head_;
  for (size_type i = 1; i <= n; ++i) {
    tmp->next_ = new node(tmp);
    tmp->next_->value_ = i;
    node_tail_ = tmp;
    tmp = tmp->next_;
  }
  node_tail_ = tmp;
}

template <class T>
s21::list<T>::list(const std::initializer_list<T> &items) : list(items.size()) {
  // std::copy(items.begin(), items.end(), )
}

template <typename T>
s21::list<T>::~list() {
  if (this->size_ == 0) return;
  node *tmp = this->node_tail_;
  for (size_type i = size_; i > 0; --i) {
    tmp = tmp->prev_;
    delete tmp->next_;
  }
  delete tmp;
  std::cout << "hello";  // add in new versions)
}

template <class T>
s21::list<T>::node *s21::list<T>::getHead() {
  return this->node_head_;
}

// Конструкторы и деструкторы внутреннего класса Iterator

template <typename T>
s21::list<T>::ListIterator::ListIterator() {
  ptr_node_ = nullptr;
}

template <typename T>
s21::list<T>::ListIterator::ListIterator(s21::list<T>::node *list_node) {
  ptr_node_ = list_node;
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
  ptr_node_ = ptr_node_->prev_;
  return *this;
}

template <typename T>
s21::list<T>::node *s21::list<T>::ListIterator::getNode() {
  return ptr_node_;
}
template <class T>
s21::list<T>::node *s21::list<T>::getTail() {
  return this->node_tail_;
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

template <class T>
s21::list<T>::iterator s21::list<T>::begin() {
  ListIterator iter(this->node_head_);
  return iter;
}
template <class T>
s21::list<T>::iterator s21::list<T>::end() {
  ListIterator iter(this->node_tail_);

  return iter;
}

#endif /** CPP2_S21_CONTAINERS_1_LIST_LIST_CC_ */