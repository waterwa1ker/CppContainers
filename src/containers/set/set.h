#ifndef CPP2_S21_CONTAINERS_1_SET_SET_H_
#define CPP2_S21_CONTAINERS_1_SET_SET_H_

#include "../virt_class/virt_class.h"

namespace s21 {

template <typename T, typename S = T>
class set : public virtual_map_set<T, S> {
 public:
  using key_type = T;
  using value_type = std::pair<const T, T>;
  using refernce = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_set<T, S>;
  using const_iterator = const iterator_set<T, S>;
  using size_type = size_t;

  set() {};
  set(std::initializer_list<key_type> const &items);
  set(set &s);
  set(set &&s);
  ~set() { this->destroy(this->root_); };
  set &operator=(set &s);
  set &operator=(set &&s);

  iterator begin();
  iterator end();

  std::pair<iterator, bool> insert(const key_type &key);
  void erase(iterator pos);

  void merge(set &other);

  iterator find(const T &key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args &&...args);

 protected:
  std::pair<iterator, bool> push(node<T, S> *(&knot), std::pair<T, S> value);
};  // set
}  // namespace s21

#include "./set.cc"

#endif  // CPP2_S21_CONTAINERS_1_SET_SET_H_