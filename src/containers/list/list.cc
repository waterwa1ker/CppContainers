#include "list.h"

template <typename T>
s21::list<T>::list(size_type n) : size_(n), capacity_(0) {
  data_ = new T[n];
}

template <typename T>
s21::list<T>::list() : list(1) {}

template <typename T>
s21::list<T>::~list() {
  delete[] data_;
}

template <typename T>
bool s21::list<T>::empty() {
  return size_ == 0;
}

template <typename T>
s21::list<T>::size_type s21::list<T>::size() {
  return size_;
}