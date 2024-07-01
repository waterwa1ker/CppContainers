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
  using const_reference = const T&;
  using size_type = std::size_t;

  Stack() : size_(0), capacity_(INITIAL_CAPACITY) {
    data_ = new value_type[capacity_];
  }

  Stack(std::initializer_list<value_type> const& items)
      : size_(0), capacity_(INITIAL_CAPACITY) {
    data_ = new value_type[capacity_];
    for (auto i = items.begin(); i != items.end(); i++) {
      push(*i);
    }
  }

  Stack(const Stack& s) : size_(s.size_), capacity_(s.capacity_) {
    CopyData(s.data_);
  }

  Stack(Stack&& s) : size_(s.size_), capacity_(s.capacity_) {
    CopyData(s.data_);
    s.size_ = 0;
    s.capacity_ = 0;
    s.data_ = nullptr;
  }

  ~Stack() {
    if (data_) {
      delete[] data_;
    }
  }

  // ВНИМАТЕЛЬНЕЕ С ЭТИМ МЕТОДОМ
  Stack operator=(Stack&& s) {
    if (data_) {
      delete data_;
    }
    size_ = s.size_;
    capacity_ = s.capacity_;
    data_ = new value_type[size_];
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = s.data_[i];
    }
    s.size_ = 0;
    s.data_ = nullptr;
    s.capacity_ = 0;
    return *this;
  }

  void push(value_type value) {
    if (size_ == capacity_) {
      capacity_ *= 2;
      value_type* new_data = new value_type[capacity_];
      CopyData(new_data);
      delete[] data_;
      data_ = new_data;
    }
    data_[size_++] = value;
  }

  void pop() {
    if (size_ == 0) {
      throw std::out_of_range("Stack is empty");
    }
    --size_;
  }

  const_reference top() {
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
  value_type* GetData() { return data_; }

 private:
  void CopyData(value_type* old_data) {
    if (data_) {
      delete[] data_;
    }
    data_ = new value_type[size_];
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = old_data[i];
    }
  }

  void CopyToNewData(value_type* new_data) {
    for (size_type i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
  }

  value_type* data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_STACK_H
