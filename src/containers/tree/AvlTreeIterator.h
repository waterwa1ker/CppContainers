// ПОМЕНЯТЬ МАКРОС
#ifndef CPP2_S21_CONTAINERS_1_AVLTREEITERATOR_H
#define CPP2_S21_CONTAINERS_1_AVLTREEITERATOR_H

#include "../stack/Stack.h"
#include "../tree/AvlTree.h"

namespace s21 {
template <typename T>
class AvlTreeIterator {
 public:
  using value_type = T;

  AvlTreeIterator(AvlTree<value_type>* root) {
    while (root != nullptr) {
      stack.push(root);
      root = root->GetLeft();
    }
  }

  bool hasNext() { return !stack.empty(); }

  value_type next() {
    AvlTree<value_type>* top = stack.top();
    stack.pop();
    AvlTree<value_type>* tmp = top->GetRight();
    while (tmp != nullptr) {
      stack.push(tmp);
      tmp = tmp->GetLeft();
    }
    return top->GetValue();
  }

 private:
  s21::Stack<AvlTree<T>*> stack;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_AVLTREEITERATOR_H
