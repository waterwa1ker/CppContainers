#ifndef CPP2_S21_CONTAINERS_1_QUEUE_QUEUE_CC_
#define CPP2_S21_CONTAINERS_1_QUEUE_QUEUE_CC_
#include "queue.h"

template <typename T>
s21::queue<T>::queue() : list<T>() {}

template <typename T>
s21::queue<T>::queue(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <typename T>
s21::queue<T>::queue(const queue &q) : list<T>(q) {}

template <typename T>
s21::queue<T>::queue(queue &&q) : list<T>(std::move(q)) {}

template <typename T>
s21::queue<T>::~queue() {}

template <typename T>
s21::queue<T> s21::queue<T>::operator=(queue &&q) {
  s21::list<T>::clear();
  this = q;
  return *this;
}

template <typename T>
void s21::queue<T>::push(const_reference value) {
  s21::list<T>::push_back(value);
}

template <typename T>
void s21::queue<T>::pop() {
  s21::list<T>::pop_front();
}

template <typename T>
void s21::queue<T>::swap(queue &other) {
  s21::list<T>::swap(other);
}

#endif  // CPP2_S21_CONTAINERS_1_QUEUE_QUEUE_CC_