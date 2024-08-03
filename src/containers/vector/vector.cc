#ifndef CPP2_S21_CONTAINERS_1_VECTOR_VECTOR_CC_
#define CPP2_S21_CONTAINERS_1_VECTOR_VECTOR_CC_
#include "./vector.h"

template <class T>
s21::vector<T>::vector() : arr_(nullptr), size_(0), capacity_(0) {}

template <class T>
s21::vector<T>::vector(size_t n)
    : arr_(new value_type[n]), size_(n), capacity_(n) {
  if (this->arr_ == nullptr) {
    throw std::length_error("vector: bad alloc");
  }
  for (size_type i = 0; i < n; ++i) {
    this->arr_[i] = T();
  }
}

template <class T>
s21::vector<T>::vector(const std::initializer_list<T> &items)
    : vector(items.size()) {
  for (size_type i = 0; i < size_; ++i) {
    this->arr_[i] = *(items.begin() + i);
  }
}

template <class T>
s21::vector<T>::vector(const s21::vector<T> &v) : vector(v.size_) {
  for (size_type i = 0; i < size_; ++i) {
    this->arr_[i] = v.arr_[i];
  }
}

template <class T>
s21::vector<T>::vector(s21::vector<T> &&v) noexcept {
  this->size_ = v.size_;
  v.size_ = 0;
  this->capacity_ = v.capacity_;
  v.capacity_ = 0;
  this->arr_ = v.arr_;
  v.arr_ = nullptr;
}

template <class T>
s21::vector<T>::~vector() {
  delete[] this->arr_;
  this->arr_ = nullptr;
  this->size_ = 0;
  this->capacity_ = 0;
}

template <class T>
s21::vector<T> &s21::vector<T>::operator=(s21::vector<T> &&v) noexcept {
  if (this != &v) {
    this->swap(v);
  }
  return *this;
}

template <class T>
T &s21::vector<T>::at(size_t pos) {
  if (pos >= this->size_ || this->size_ == 0) {
    throw std::length_error("Index out range");
  }
  return this->arr_[pos];
}

template <class T>
T &s21::vector<T>::operator[](size_t pos) {
  return *(arr_ + pos);
}

template <class T>
const T &s21::vector<T>::front() {
  return *arr_;
}

template <class T>
const T &s21::vector<T>::back() {
  return arr_[size_ - 1];
}

template <class T>
T *s21::vector<T>::data() noexcept {
  return arr_;
}

template <class T>
T *s21::vector<T>::begin() {
  return arr_;
}

template <class T>
T *s21::vector<T>::end() {
  return arr_ + size_;
}

template <class T>
bool s21::vector<T>::empty() const noexcept {
  return arr_ == nullptr;
}

template <class T>
size_t s21::vector<T>::size() {
  return this->size_;
}

template <class T>
size_t s21::vector<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
}

template <class T>
void s21::vector<T>::reserve(size_t size) {
  if (size > max_size()) {
    throw std::length_error("No memmory");
  }
  if (size >= this->size_) {
    vector<value_type> tmp(size);
    for (size_type i = 0; i < this->size_; ++i) {
      tmp.arr_[i] = this->arr_[i];
    }
    tmp.size_ = this->size_;
    *this = std::move(tmp);
  }
}

template <class T>
size_t s21::vector<T>::capacity() {
  return this->capacity_;
}

template <class T>
void s21::vector<T>::shrink_to_fit() {
  if (this->size_ != this->capacity_) {
    vector<value_type> tmp(size_);
    for (size_type i = 0; i < this->size_; ++i) {
      tmp.arr_[i] = this->arr_[i];
    }
    *this = std::move(tmp);
  }
}

template <class T>
void s21::vector<T>::clear() {
  delete[] this->arr_;
  this->arr_ = nullptr;
  this->size_ = 0;
}

template <class T>
T *s21::vector<T>::insert(T *pos, const T &value) {
  vector<value_type> tmp(this->size_ + 1);
  size_type j = 0;
  size_type pos_this = pos - this->begin();
  for (size_type i = 0; i < tmp.size_; ++i) {
    if (i == pos_this) {
      tmp.arr_[i] = value;
    } else {
      tmp.arr_[i] = this->arr_[j++];
    }
  }
  *this = std::move(tmp);
  return arr_ + pos_this;
}

template <class T>
void s21::vector<T>::erase(T *pos) {
  vector<value_type> tmp(this->size_ - 1);
  size_type j = 0;
  size_type pos_this = pos - this->begin();
  for (size_type i = 0; i < this->size_; ++i) {
    if (i != pos_this) {
      tmp.arr_[j++] = this->arr_[i];
    }
  }
  *this = std::move(tmp);
}

template <class T>
void s21::vector<T>::push_back(const T &value) {
  if (this->capacity_ > this->size_) {
    arr_[size_] = value;
    size_ += 1;
  } else {
    vector<value_type> tmp(this->size_ + 1);
    for (size_type i = 0; i < this->size_; ++i) {
      tmp.arr_[i] = this->arr_[i];
    }
    tmp[size_] = value;
    *this = std::move(tmp);
  }
}

template <class T>
void s21::vector<T>::pop_back() {
  size_ -= 1;
}

template <class T>
void s21::vector<T>::swap(s21::vector<T> &other) noexcept {
  value_type *tmp_arr = this->arr_;
  size_type tmp_size = this->size_;
  size_type tmp_capacity = this->capacity_;
  this->arr_ = other.arr_;
  this->size_ = other.size_;
  this->capacity_ = other.capacity_;
  other.arr_ = tmp_arr;
  other.size_ = tmp_size;
  other.capacity_ = tmp_capacity;
}

#endif  // CPP2_S21_CONTAINERS_1_VECTOR_VECTOR_CC_