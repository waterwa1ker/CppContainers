#ifndef CPP2_S21_CONTAINERS_1_LIST_LIST_CC_
#define CPP2_S21_CONTAINERS_1_LIST_LIST_CC_
#include "./list.h"

// Определение структуры

template <typename T>
struct s21::list<T>::node {
  value_type value_;
  node *next_;
  node *prev_;
  node() : next_(nullptr), prev_(nullptr) {}
  node(node *now) : next_(nullptr), prev_(now) {}
};

// Конструкторы

template <typename T>
s21::list<T>::list() {
  node_head_ = nullptr;
  node_tail_ = nullptr;
  size_ = 0;
}

template <typename T>
s21::list<T>::list(size_type n) {
  node_head_ = new node;
  size_ = n;

  node *tmp = node_head_;
  for (size_type i = 1; i <= n; ++i) {
    tmp->next_ = new node(tmp);
    node_tail_ = tmp;
    tmp = tmp->next_;
  }
  node_tail_ = tmp;
}

template <typename T>
s21::list<T>::list(const std::initializer_list<T> &items) : list(items.size()) {
  node *tmp = node_head_;
  for (T item : items) {
    tmp->value_ = item;
    tmp = tmp->next_;
  }
}

template <typename T>
s21::list<T>::list(const s21::list<T> &l) : list(l.size_) {
  node *tmp_this = this->node_head_;
  node *tmp_l = l.node_head_;
  for (size_type i = 0; i < l.size_; ++i) {
    tmp_this->value_ = tmp_l->value_;
    tmp_this = tmp_this->next_;
    tmp_l = tmp_l->next_;
  }
}
template <typename T>
s21::list<T>::list(s21::list<T> &&l) {
  this->node_head_ = l.node_head_;
  this->node_tail_ = l.node_tail_;
  this->size_ = l.size_;
  l.node_head_ = nullptr;
  l.node_tail_ = nullptr;
  l.size_ = 0;
}

template <typename T>
bool s21::list<T>::operator=(s21::list<T> &&l) {
  this->node_head_ = l.node_head_;
  this->node_tail_ = l.node_tail_;
  this->size_ = l.size_;
  l.node_head_ = nullptr;
  l.node_tail_ = nullptr;
  l.size_ = 0;
  return true;
}

template <typename T>
s21::list<T>::~list() {
  this->clear();
}

// Access

template <typename T>
const T &s21::list<T>::front() {
  return (this->node_head_->value_);
}

template <typename T>
const T &s21::list<T>::back() {
  return this->node_tail_->prev_->value_;
}

template <typename T>
bool s21::list<T>::empty() {
  return size_ == 0;
}

template <typename T>
size_t s21::list<T>::size() {
  return this->size_;
}

template <typename T>
typename s21::list<T>::node *s21::list<T>::getHead() {
  return this->node_head_;
}

// another

template <typename T>
void s21::list<T>::clear() {
  if (this->size_ == 0) return;
  node *tmp = this->node_tail_;
  for (size_type i = size_; i > 0; --i) {
    tmp = tmp->prev_;
    delete tmp->next_;
  }
  delete tmp;
  this->node_head_ = nullptr;
  this->node_tail_ = nullptr;
  this->size_ = 0;
}

// Осталось 1 метода

template <typename T>
size_t s21::list<T>::max_size() {
  return (std::numeric_limits<std::size_t>::max() / sizeof(node) / 2);
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::insert(s21::list<T>::iterator pos,
                                                     const T &value) {
  node *tmp = pos.getNode();
  node *tmp_p = tmp->prev_;
  node *new_node = new node;
  new_node->next_ = tmp;
  new_node->prev_ = tmp_p;
  if (tmp_p != nullptr) {
    tmp_p->next_ = new_node;
  } else {
    this->node_head_ = new_node;
  }
  tmp->prev_ = new_node;
  new_node->value_ = value;
  this->size_ += 1;
  return iterator(new_node);
}

// Заёбисто сортирует :( прийдётся писать ещё один сортировщик(
// как работает сортировка в данном случае он сравнивает 1 элемент this с первым
// элементом в other и так далее
// this.value <= other.value and other.value != this.next.value если это не так
// то в конец добавляется
template <typename T>
void s21::list<T>::merge(s21::list<T> &other) {
  if (other.size_ == 0) return;
  if (this->size_ == 0) {
    this->splice(this->begin(), other);
    return;
  }
  node *tmp_this_node = this->node_head_;
  node *tmp_other_node = other.node_head_;
  for (size_type n = 0; n < this->size_ and other.size_ != 0; ++n) {
    if (tmp_other_node->value_ <= tmp_this_node->value_ and
        tmp_other_node->next_ != nullptr) {
      node *tmp_other_next = tmp_other_node->next_;

      if (tmp_this_node->prev_ == nullptr) {
        tmp_this_node->prev_ = tmp_other_node;
        tmp_other_node->next_ = tmp_this_node;
        tmp_other_node->prev_ = nullptr;
        this->node_head_ = tmp_other_node;
      } else {
        node *tmp_this_p = tmp_this_node->prev_;
        tmp_this_node->prev_ = tmp_other_node;
        tmp_other_node->next_ = tmp_this_node;
        tmp_other_node->prev_ = tmp_this_p;
        tmp_this_p->next_ = tmp_other_node;
      }

      this->size_ += 1;
      other.size_ -= 1;
      tmp_other_node = tmp_other_next;
      other.node_head_ = tmp_other_node;
    } else {
      tmp_this_node = tmp_this_node->next_;
    }
  }
  this->splice(this->end(), other);
  other.node_head_ = nullptr;
  delete other.node_tail_;
  other.node_tail_ = nullptr;
  other.size_ = 0;
}

template <typename T>
void s21::list<T>::splice(s21::list<T>::iterator pos, s21::list<T> &other) {
  node *pos_node = pos.getNode();
  if (pos_node == this->node_head_ and pos_node == nullptr) {
    this->node_head_ = other.node_head_;
    this->node_tail_ = other.node_tail_;
    this->size_ = other.size_;
  } else {
    node *pos_pr = pos_node->prev_;

    if (pos_pr != nullptr) {
      pos_pr->next_ = other.node_head_;
      other.node_head_->prev_ = pos_pr;
    } else {
      this->node_head_ = other.node_head_;
    }

    node *tmp = other.node_tail_->prev_;
    tmp->next_ = pos_node;
    pos_node->prev_ = other.node_tail_->prev_;
    delete other.node_tail_;
    this->size_ += other.size_;
  }
  other.size_ = 0;
  other.node_head_ = nullptr;
  other.node_tail_ = nullptr;
}

template <typename T>
void s21::list<T>::erase(s21::list<T>::iterator pos) {
  if (this->size_ == 0 or pos == this->end()) {
    return;  // add sega like this:
    /*
    a.out(15287,0x2025c4c00) malloc: *** error for object 0x16f21b040: pointer
    being freed was not allocated
    a.out(15287,0x2025c4c00) malloc: *** set a breakpoint in malloc_error_break
    to debug
    */
  }

  node *tmp = pos.getNode();
  node *tmp_n = tmp->next_;
  node *tmp_p = tmp->prev_;
  if (tmp->prev_ == nullptr) {
    this->node_head_ = tmp_n;
    this->node_head_->prev_ = nullptr;
  } else {
    tmp_p->next_ = tmp_n;
    tmp_n->prev_ = tmp_p;
    tmp->next_ = nullptr;
    tmp->prev_ = nullptr;
  }
  delete tmp;
  this->size_ -= 1;
}

template <typename T>
void s21::list<T>::push_back(const T &value) {
  if (this->size_ == 0) {
    this->node_head_ = new node;
    node_head_->value_ = value;
    this->node_head_->next_ = new node(this->node_head_);
    node_tail_ = this->node_head_->next_;
    size_ = 1;
  } else {
    node *tmp = node_head_;
    while (tmp->next_ != nullptr) {
      tmp = tmp->next_;
    }
    tmp->next_ = new node(tmp);
    node_tail_ = tmp->next_;
    tmp->value_ = value;
    size_ += 1;
  }
}

template <typename T>
void s21::list<T>::pop_back() {
  if (size_ == 0) return;
  node *tmp = node_tail_;
  tmp = tmp->prev_;
  delete tmp->next_;
  node_tail_ = tmp;
  size_ -= 1;
}

template <typename T>
void s21::list<T>::push_front(const T &value) {
  if (size_ == 0) {
    this->push_back(value);
  } else {
    node *tmp = node_head_;
    node_head_ = new node;
    node_head_->next_ = tmp;
    tmp->prev_ = node_head_;
    node_head_->value_ = value;
    size_ += 1;
  }
}

template <typename T>
void s21::list<T>::pop_front() {
  if (size_ == 0)
    return;
  else {
    this->node_head_ = node_head_->next_;
    delete node_head_->prev_;
    node_head_->prev_ = nullptr;
    this->size_ -= 1;
  }
}

template <typename T>
void s21::list<T>::swap(s21::list<T> &other) {
  if (this == &other) return;

  size_type tmp_size = this->size_;
  this->size_ = other.size_;
  other.size_ = tmp_size;

  node *tmp = this->node_head_;
  this->node_head_ = other.node_head_;
  other.node_head_ = tmp;

  tmp = this->node_tail_;
  this->node_tail_ = other.node_tail_;
  other.node_tail_ = tmp;
}

template <typename T>
void s21::list<T>::sort() {
  if (size_ == 0 or size_ == 1) {
    return;
  }
  node *tmp = this->node_head_;
  for (size_type n = 0; n < this->size_ - 1; ++n) {
    node *nod = tmp;
    for (size_type i = 0; i < this->size_ - 1 - n; ++i) {
      node *point = nod;
      node *point_next = nod->next_;
      if (point->value_ > point_next->value_) {
        T val = point->value_;
        point->value_ = point_next->value_;
        point_next->value_ = val;
      }
      nod = nod->next_;
    }
  }
}

template <typename T>
void s21::list<T>::unique() {
  if (size_ == 0) {
    return;
  }
  node *tmp = this->node_head_;
  node *check = this->node_head_->next_;
  size_type s = this->size_;
  for (size_type i = 0; i < s; ++i) {
    if (tmp->value_ == check->value_) {
      node *point_n = check->next_;
      node *point_p = check->prev_;
      check->next_ = nullptr;
      check->prev_ = nullptr;
      delete check;
      check = point_n;
      point_p->next_ = point_n;
      point_n->prev_ = point_p;
      this->size_ -= 1;
      if (check == nullptr or tmp == nullptr) break;
    } else {
      tmp = tmp->next_;
      check = tmp->next_;
    }
  }
}

template <typename T>
void s21::list<T>::reverse() {
  size_type part_s = this->size_ / 2;
  node *tmp_h = this->node_head_;
  node *tmp_t = this->node_tail_->prev_;

  for (size_type i = 0; i < part_s; ++i) {
    T val = tmp_h->value_;
    tmp_h->value_ = tmp_t->value_;
    tmp_t->value_ = val;

    tmp_h = tmp_h->next_;
    tmp_t = tmp_t->prev_;
  }
}

// Конструкторы и деструкторы внутреннего класса Iterator

template <typename T>
s21::list<T>::ListIterator::ListIterator() {
  ptr_node_ = nullptr;
}

template <typename T>
s21::list<T>::ListIterator::ListIterator(s21::list<T>::node *list_node) {
  ptr_node_ = list_node;
}

template <typename T>
s21::list<T>::ListIterator::~ListIterator() {
  ptr_node_ = nullptr;
}

template <typename T>
T s21::list<T>::ListIterator::operator*() {
  return ptr_node_->value_;
}

template <typename T>
typename s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator++() {
  // проверить как ведёт себя если это конечная нода
  if (ptr_node_->next_ != nullptr) {
    ptr_node_ = ptr_node_->next_;
  } else {
    while (true) {
      if (ptr_node_->prev_ == nullptr) break;
      ptr_node_ = ptr_node_->prev_;
    }
  }
  return *this;
}

template <typename T>
typename s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator--() {
  // проверить как ведёт себя если это конечная нода
  if (ptr_node_->prev_ != nullptr) {
    ptr_node_ = ptr_node_->prev_;
  } else {
    while (true) {
      if (ptr_node_->next_ == nullptr) break;
      ptr_node_ = ptr_node_->next_;
    }
  }
  return *this;
}

template <typename T>
typename s21::list<T>::node *s21::list<T>::ListIterator::getNode() const {
  return ptr_node_;
}

template <typename T>
typename s21::list<T>::node *s21::list<T>::getTail() {
  return this->node_tail_;
}

template <typename T>
bool s21::list<T>::ListIterator::operator==(
    const s21::list<T>::ListIterator &iter) const {
  return this->ptr_node_ == iter.ptr_node_;
}

template <typename T>
bool s21::list<T>::ListIterator::operator!=(
    const s21::list<T>::ListIterator &iter) const {
  return this->ptr_node_ != iter.ptr_node_;
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  ListIterator iter(this->node_head_);
  return iter;
}
template <typename T>
typename s21::list<T>::iterator s21::list<T>::end() {
  ListIterator iter(this->node_tail_);

  return iter;
}

#endif /** CPP2_S21_CONTAINERS_1_LIST_LIST_CC_ */