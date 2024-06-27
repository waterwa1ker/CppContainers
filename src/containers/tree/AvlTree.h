#ifndef CONTAINERS_SRC_CONTAINERS_TREE_TREE_H_
#define CONTAINERS_SRC_CONTAINERS_TREE_TREE_H_

#include <iostream>

namespace s21 {

template <typename T>
class AvlTree {
 public:
  class TreeIterator;

  AvlTree(T key, T value)
      : key_(key), value_(value), left_(nullptr), right_(nullptr) {}

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

  void Balance(AvlTree<T> *tree) {
    int balance = GetBalance(tree);
    if (balance == -2) {
      if (GetBalance(tree->left_) == 1) {
        RotateLeft(tree->left_);
      }
      RotateRight(tree);
    } else if (balance == 2) {
      if (GetBalance(tree->right_) == -1) {
        RotateRight(tree->right_);
      }
      RotateLeft(tree);
    }
  }

  void Insert(AvlTree<T> *tree, T key, T value) {
    if (key < tree->key_) {
      if (tree->left_ == nullptr) {
        AvlTree<T> *new_tree = new AvlTree(key, value);
        new_tree->UpdateHeight(new_tree);
        tree->left_ = new_tree;
      } else {
        this->Insert(tree->left_, key, value);
      }
    } else {
      if (tree->right_ == nullptr) {
        AvlTree<T> *new_tree = new AvlTree(key, value);
        new_tree->UpdateHeight(new_tree);
        tree->right_ = new_tree;
      } else {
        this->Insert(tree->right_, key, value);
      }
    }
    UpdateHeight(tree);
    Balance(tree);
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

  void Swap(AvlTree<T> *first, AvlTree<T> *second) {
    T tmp_key = first->key_;
    first->key_ = second->key_;
    second->key_ = tmp_key;
    T tmp_value = first->value_;
    first->value_ = second->value_;
    second->value_ = tmp_value;
  }

  // TEST IT
  void RotateRight(AvlTree<T> *tree) {
    Swap(tree, tree->left_);
    AvlTree<T> *tmp = tree->right_;
    tree->right_ = tree->left_;
    tree->left_ = tree->right_->left_;
    tree->right_->left_ = tree->right_->right_;
    tree->right_->right_ = tmp;
    UpdateHeight(tree->right_);
    UpdateHeight(tree);
  }

  void RotateLeft(AvlTree<T> *tree) {
    Swap(tree, tree->right_);
    AvlTree<T> *tmp = tree->left_;
    tree->left_ = tree->right_;
    tree->right_ = tree->left_->right_;
    tree->left_->right_ = tree->left_->left_;
    tree->left_->left_ = tmp;
    UpdateHeight(tree->left_);
    UpdateHeight(tree);
  }

  void PrintTreeRight(AvlTree<T> *tree) {
    if (tree != nullptr) {
      PrintTree(tree->left_);
      std::cout << tree->value_ << " ";
      PrintTree(tree->right_);
    }
  }

  AvlTree<T> *GetMax(AvlTree<T> *tree) {
    AvlTree<T> *result = nullptr;
    if (tree != nullptr) {
      if (tree->right_ != nullptr) {
        result = GetMax(tree->right_);
      } else {
        result = tree;
      }
    }
    return result;
  }

  AvlTree<T> *GetMin(AvlTree<T> *tree) {
    AvlTree<T> *result = nullptr;
    if (tree != nullptr) {
      if (tree->left_ != nullptr) {
        result = GetMin(tree->left_);
      } else {
        result = tree;
      }
    }
    return result;
  }

  // TODO
  AvlTree<T> *Remove(AvlTree<T> *tree, T key) { return nullptr; }

  bool operator==(const AvlTree<T> &other) {
    return key_ == other.key_ && value_ == other.value_;
  }

  // �������, �������
  T GetKey() { return key_; }
  T GetValue() { return value_; }
  AvlTree<T> *GetLeft() { return left_; }
  AvlTree<T> *GetRight() { return right_; }

  // TEST
  class TreeIterator {
   public:
    TreeIterator(T *first) : current_(first) {}

    T &operator+(int n) { return *(current_ + n); }
    T &operator-(int n) { return *(current_ - n); }

    T &operator++() { return *current_++; }
    T &operator--() { return *current_--; }

    bool operator!=(const TreeIterator &other) {
      return current_ != other.current_;
    }
    bool operator==(const TreeIterator &other) {
      return current_ == other.current_;
    }

   private:
    T *current_;
  };

 private:
  T key_;
  T value_;
  AvlTree<T> *left_;
  AvlTree<T> *right_;
  int height_;
};

}  // namespace s21

#endif  // CONTAINERS_SRC_CONTAINERS_TREE_TREE_H_