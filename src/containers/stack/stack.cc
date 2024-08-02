#ifndef CPP2_S21_CONTAINERS_1_STACK_STACK_CC_
#define CPP2_S21_CONTAINERS_1_STACK_STACK_CC_
#include "stack.h"

template <typename T>
s21::stack<T>::stack() : list<T>() {}

template <typename T>
s21::stack<T>::stack(std::initializer_list<value_type> const &items)
    : list<T>(items) {}

template <typename T>
s21::stack<T>::stack(const stack &s) : list<T>(s) {}

template <typename T>
s21::stack<T>::stack(stack &&s) noexcept : list<T>(std::move(s)) {}

template <typename T>
s21::stack<T>::~stack() = default;

template <typename T>
s21::stack<T> &s21::stack<T>::operator=(stack &&s) noexcept {
  if (this != &s) {
    list<T>::clear();
    list<T>::operator=(std::move(s));
  }
  return *this;
}

template <typename T>
typename s21::stack<T>::const_reference s21::stack<T>::top() {
  return s21::list<T>::back();
}

template <typename T>
void s21::stack<T>::push(const_reference value) {
  s21::list<T>::push_back(value);
}

template <typename T>
void s21::stack<T>::pop() {
  s21::list<T>::pop_back();
}

template <typename T>
void s21::stack<T>::swap(stack &other) {
  s21::list<T>::swap(other);
}

#endif  // CPP2_S21_CONTAINERS_1_STACK_STACK_CC_