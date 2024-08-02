#ifndef CPP2_CONTAINERS_QUEUE_S21_QUEUE_H_
#define CPP2_CONTAINERS_QUEUE_S21_QUEUE_H_

#include "../list/list.h"

namespace s21 {
template <typename T>
class queue : public list<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();

  queue operator=(queue &&q);

  void push(const_reference value);
  void pop();
  void swap(queue &other);
};
}  // namespace s21

#include "queue.cc"

#endif  // CPP2_CONTAINERS_QUEUE_S21_QUEUE_H_