#ifndef CPP2_CONTAINERS_STACK_S21_STACK_H_
#define CPP2_CONTAINERS_STACK_S21_STACK_H_

#include <iostream>

#include "../list/list.h"

namespace s21 {
template <typename T>
class stack : public list<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s) noexcept;
  ~stack();

  stack &operator=(stack &&s) noexcept;

  const_reference top();

  void push(const_reference value);
  void pop();
  void swap(stack &other);
};
}  // namespace s21

#include "stack.cc"

#endif  // CPP2_CONTAINERS_STACK_S21_STACK_H_
