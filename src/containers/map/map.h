#ifndef CPP2_S21_CONTAINERS_1_MAP_MAP_H_
#define CPP2_S21_CONTAINERS_1_MAP_MAP_H_

#include "../virt_class/virt_class.h"

namespace s21 {
template <typename T, typename S>
class map : public virtual_map_set<T, S> {
 public:
  using key_type = T;
  using mapped_type = S;
  using value_type = std::pair<const key_type, mapped_type>;
  using refernce = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_map<T, S>;
  using size_type = size_t;

  map() {};
  map(std::initializer_list<value_type> const &items);
  map(map &m);
  map(map &&m);
  ~map();
  map &operator=(map &m);
  map &operator=(map &&m);

  S &at(const T &key);
  S &operator[](const T &key);
  iterator begin();
  iterator end();

  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const T &key, const S &obj);
  std::pair<iterator, bool> insert_or_assign(const T &key, const S &obj);
  void erase(iterator pos);

  void merge(map &other);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args &&...args);

 private:
  std::pair<iterator, bool> insert_or_assign_privat(const std::pair<T, S> value,
                                                    node<T, S> *(&knot));
  std::pair<iterator, bool> push(node<T, S> *(&knot), std::pair<T, S> value);
};
}  // namespace s21

#include "./map.cc"

#endif  // CPP2_S21_CONTAINERS_1_MAP_MAP_H_