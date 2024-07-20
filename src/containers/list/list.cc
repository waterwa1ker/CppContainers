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

template <class T>
s21::list<T>::list() {
  node_head_ = nullptr;
  node_tail_ = nullptr;
  size_ = 0;
}

template <class T>
s21::list<T>::list(size_type n) {
  node_head_ = new node;
  size_ = n;

  node *tmp = node_head_;
  for (size_type i = 1; i <= n; ++i) {
    tmp->next_ = new node(tmp);
    node_tail_ = tmp;
    tmp = tmp->next_;
  }
  node_tail_ = tmp;
}

template <class T>
s21::list<T>::list(const std::initializer_list<T> &items) : list(items.size()) {
  node *tmp = node_head_;
  for (T item : items) {
    tmp->value_ = item;
    tmp = tmp->next_;
  }
}

template <class T>
s21::list<T>::list(const s21::list<T> &l) : list(l.size_) {
  node *tmp_this = this->node_head_;
  node *tmp_l = l.node_head_;
  for (size_type i = 0; i < l.size_; ++i) {
    tmp_this->value_ = tmp_l->value_;
    tmp_this = tmp_this->next_;
    tmp_l = tmp_l->next_;
  }
}
template <class T>
s21::list<T>::list(s21::list<T> &&l) {
  this->node_head_ = l.node_head_;
  this->node_tail_ = l.node_tail_;
  this->size_ = l.size_;
  l.node_head_ = nullptr;
  l.node_tail_ = nullptr;
  l.size_ = 0;
}

template <class T>
bool s21::list<T>::operator=(s21::list<T> &&l) {
  this->node_head_ = l.node_head_;
  this->node_tail_ = l.node_tail_;
  this->size_ = l.size_;
  l.node_head_ = nullptr;
  l.node_tail_ = nullptr;
  l.size_ = 0;
  return true;
}

template <class T>
s21::list<T>::~list() {
  this->clear();
}

// Access

template <class T>
const T &s21::list<T>::front() {
  return (this->node_head_->value_);
}

template <class T>
const T &s21::list<T>::back() {
  return this->node_tail_->prev_->value_;
}

template <class T>
bool s21::list<T>::empty() {
  return size_ == 0;
}

template <class T>
size_t s21::list<T>::size() {
  return this->size_;
}

template <class T>
s21::list<T>::node *s21::list<T>::getHead() {
  return this->node_head_;
}

// another

template <class T>
void s21::list<T>::clear() {
  if (this->size_ == 0) return;
  node *tmp = this->node_tail_;
  for (size_type i = size_; i > 0; --i) {
    tmp = tmp->prev_;
    delete tmp->next_;
  }
  delete tmp;
  this->node_head_ = nullptr;
  this->node_tail_ = nullptr;
  this->size_ = 0;
}

template <class T>
void s21::list<T>::push_front(const T &value) {
  if (this->size_ == 0) {
    this->node_head_ = new node;
    node_head_->value_ = value;
    this->node_head_->next_ = new node(this->node_head_);
    node_tail_ = this->node_head_->next_;
    size_ = 1;
  } else {
    node *tmp = node_head_;
    while (tmp->next_ != nullptr) {
      tmp = tmp->next_;
    }
    tmp->next_ = new node(tmp);
    node_tail_ = tmp->next_;
    tmp->value_ = value;
    size_ += 1;
  }
}

// Конструкторы и деструкторы внутреннего класса Iterator

template <class T>
s21::list<T>::ListIterator::ListIterator() {
  ptr_node_ = nullptr;
}

template <class T>
s21::list<T>::ListIterator::ListIterator(s21::list<T>::node *list_node) {
  ptr_node_ = list_node;
}

template <class T>
s21::list<T>::ListIterator::~ListIterator() {
  ptr_node_ = nullptr;
}

template <class T>
T s21::list<T>::ListIterator::operator*() {
  return ptr_node_->value_;
}

template <class T>
s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator++() {
  // проверить как ведёт себя если это конечная нода
  if (ptr_node_->next_ != nullptr) ptr_node_ = ptr_node_->next_;
  return *this;
}

template <class T>
s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator--() {
  // проверить как ведёт себя если это конечная нода
  if (ptr_node_->prev_ != nullptr) ptr_node_ = ptr_node_->prev_;

  return *this;
}

template <class T>
s21::list<T>::node *s21::list<T>::ListIterator::getNode() {
  return ptr_node_;
}
template <class T>
s21::list<T>::node *s21::list<T>::getTail() {
  return this->node_tail_;
}

template <class T>
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