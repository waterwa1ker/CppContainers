/**
 * @file list.h
 * @author jothosge
 * @brief This file keep realization list type
 */

#ifndef CPP2_S21_CONTAINERS_1_LIST_LIST_H_
#define CPP2_S21_CONTAINERS_1_LIST_LIST_H_

#include <algorithm>
#include <iostream>

namespace s21 {
/**
 * @brief list is a container that supports constant time insertion and removal
 * of elements from anywhere in the container. Fast random access is not
 * supported. It is usually implemented as a doubly-linked list
 */
template <typename T>
class list {
 public:
  class ListIterator;
  struct node;

  /** @brief T defines the type of an element (T is template parameter) */
  using value_type = T;
  /** @brief T & defines the type of the reference to an element */
  using reference = T &;
  /**  @brief const T & defines the type of the constant reference*/
  using const_reference = const T &;
  /**  @brief internal class ListConstIterator<T> defines the constant type for
   * iterating through the container
   */
  using const_iterator = const ListIterator;
  /** @brief internal class ListIterator<T> defines the type for iterating
   * through the container
   */
  using iterator = ListIterator;
  /** @brief size_t defines the type of the container size (standard type is
   * size_t)
   */
  using size_type = std::size_t;

  class ListIterator {
   public:
    ListIterator();
    ListIterator(node *);
    ~ListIterator();

    // overlaods operators
    ListIterator &operator++();
    ListIterator &operator--();
    value_type operator*();

    bool operator==(const ListIterator &) const;

    bool operator!=(const ListIterator &) const;

    node *getNode() const;

   private:
    node *ptr_node_;
  };

  /** @brief  constructor, creates empty list */
  list();
  /** @brief parameterized constructor, creates the list of size n */
  list(size_type n);
  /** @brief initializer list constructor, creates list initizialized using
   * std::initializer_list */
  list(std::initializer_list<value_type> const &items);
  /** @brief copy constructor */
  list(const list &l);
  /** @brief move constructor */
  list(list &&l);
  /** @brief destructor */
  ~list();
  /** @brief assignment operator overload for moving object */
  bool operator=(list &&l);

  /** @brief access the first element */
  const_reference front();
  /**  @brief access the last element */
  const_reference back();

  /** @brief returns an iterator to the beginning */
  iterator begin();
  /** @brief returns an iterator to the end */
  iterator end();

  /** @brief checks whether the container is empty */
  bool empty();
  /** @brief returns the number of elements */
  size_type size();
  /** @brief returns the maximum possible number of elements */
  size_type max_size();

  /** @brief clears the contents */
  void clear();
  /** @brief inserts element into concrete pos and returns the iterator that
   * points to the new element */
  iterator insert(iterator pos, const_reference value);
  /** @brief erases element at pos */
  void erase(iterator pos);
  /** @brief adds an element to the end */
  void push_back(const_reference value);
  /** @brief removes the last element */
  void pop_back();
  /** @brief adds an element to the head */
  void push_front(const_reference value);
  /** @brief removes the first element */
  void pop_front();
  /** @brief swaps the contents */
  void swap(list &other);
  /** @brief merges two sorted lists */
  void merge(list &other);
  /** @brief transfers elements from list other starting from pos */
  void splice(const_iterator pos, list &other);
  /** @brief reverses the order of the elements */
  void reverse();
  /** @brief removes consecutive duplicate elements */
  void unique();
  /**  @brief sorts the elements */
  void sort();

 private:
  node *node_head_;
  node *node_tail_;

  node *getHead();
  node *getTail();

  /** @brief keep size of list */
  size_type size_;
};
}  // namespace s21

#include "list.cc"

#endif /** CPP2_S21_CONTAINERS_1_LIST_LIST_H_ */