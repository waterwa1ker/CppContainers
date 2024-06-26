#ifndef CONTAINERS_SRC_CONTAINERS_TREE_TREE_H_
#define CONTAINERS_SRC_CONTAINERS_TREE_TREE_H_

#include <iostream>

namespace s21 {

template <typename T>
class AvlTree {
 public:
  // ������������
  AvlTree(T key, T value)
      : key_(key), value_(value), left_(nullptr), right_(nullptr) {}

  // ��������������
  int GetHeight(AvlTree<T> *tree) {
    return tree == nullptr ? -1 : tree->height_;
  }
  void UpdateHeight(AvlTree *tree) {
    tree->height_ =
        std::max(GetHeight(tree->left_), GetHeight(tree->right_)) + 1;
  }
  int GetBalance(AvlTree<T> *tree) {
    return (tree == nullptr) ? 0
                             : GetHeight(tree->right_) - GetHeight(tree->left_);
  }

  // �������
  void Insert(AvlTree<T> *tree, T key, T value) {
    if (key < tree->key_) {
      if (tree->left_ == nullptr) {
        AvlTree<T> *new_tree = new AvlTree(key, value);
        new_tree->UpdateHeight(new_tree);
        tree->left_ = new_tree;
        tree->UpdateHeight(tree);
      } else {
        this->Insert(tree->left_, key, value);
      }
    } else {
      if (tree->right_ == nullptr) {
        AvlTree<T> *new_tree = new AvlTree(key, value);
        new_tree->UpdateHeight(new_tree);
        tree->right_ = new_tree;
        tree->UpdateHeight(tree);
      } else {
        this->Insert(tree->right_, key, value);
      }
    }
  }

  AvlTree<T> *Search(AvlTree<T> *tree, T key) {
    AvlTree<T> *result = nullptr;
    if (tree != nullptr) {
      if (tree->key_ == key) {
        result = tree;
      } else if (tree->key_ > key) {
        tree->Search(tree->left_, key);
      } else {
        tree->Search(tree->right_, key);
      }
    }
    return result;
  }

  // �������, �������
  T GetKey() { return key_; }
  T GetValue() { return value_; }
  AvlTree<T> *GetLeft() { return left_; }
  AvlTree<T> *GetRight() { return right_; }

 private:
  T key_;
  T value_;
  AvlTree<T> *left_;
  AvlTree<T> *right_;
  int height_;
};

}  // namespace s21

#endif  // CONTAINERS_SRC_CONTAINERS_TREE_TREE_H_