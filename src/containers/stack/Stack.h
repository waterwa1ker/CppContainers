#ifndef CPP2_S21_CONTAINERS_1_STACK_H
#define CPP2_S21_CONTAINERS_1_STACK_H

#define INITIAL_CAPACITY 10

#include <iostream>

namespace s21 {
template <typename T>
class Stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_referense = const T&;
  using size_type = std::size_t;

  Stack() : size_(0), capacity_(INITIAL_CAPACITY) {
    data_ = new value_type[capacity_];
  }

  void push(value_type value) {
    if (size == capacity_) {
      capacity_ *= 2;
      value_type* new_data = new value_type[capacity_];
      CopyData(new_data);
      delete[] data_;
      data_ = new_data;
    }
    data_[size_++] = value;
  }

  value_type pop() {
    if (size_ == 0) {
      throw std::out_of_range("Stack is empty");
    }
    --size_;
  }

  const_referense top() {
    if (size_ == 0) {
      throw std::out_of_range("Stack is empty");
    }
    return data_[size_ - 1];
  }

  void swap(Stack& other) {
    value_type* tmp_data = other.data_;
    other.data_ = data_;
    data_ = tmp_data;
    size_type tmp_size = other.size_;
    other.size_ = size_;
    size_ = tmp_size;
    size_type tmp_capacity = other.capacity_;
    other.capacity_ = capacity_;
    capacity_ = tmp_capacity;
  }

  bool empty() { return size_ == 0; }

  size_type size() { return size_; }

  size_type GetCapacity() { return capacity_; }

 private:
  void CopyData(value_type* new_data) {
    for (size_type i = 0; i < size; ++i) {
      new_data[i] = data_[i];
    }
  }

  value_type* data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_STACK_H
