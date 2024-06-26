#include <gtest/gtest.h>

#include "../../containers/tree/AvlTree.h"

TEST(AvlTree, ConstructorWithParametrs) {
  int key = 1;
  int value = 2;
  s21::AvlTree<int> tree(key, value);
  EXPECT_EQ(key, tree.GetKey());
  EXPECT_EQ(value, tree.GetValue());
}

TEST(AvlTree, GetKey) {
  int key = 1;
  int value = -1;
  s21::AvlTree<int> tree(key, value);
  EXPECT_EQ(tree.GetKey(), key);
}

TEST(AvlTree, GetValue) {
  float key = 1.1;
  float value = -1.1;
  s21::AvlTree<float> tree(key, value);
  EXPECT_EQ(tree.GetValue(), value);
}

TEST(AvlTree, GetHeightNull) {
  int key = 1;
  int value = 2;
  s21::AvlTree<int> tree(key, value);
  s21::AvlTree<int> *left = tree.GetLeft();
  EXPECT_TRUE(left->GetHeight(left) == -1);
}

TEST(AvlTree, Insert) {
  int root_key = 1;
  int root_value = 2;
  int key = 2;
  int value = 3;
  s21::AvlTree<int> tree(root_key, root_value);
  tree.Insert(&tree, key, value);
  EXPECT_EQ(key, tree.GetRight()->GetKey());
  EXPECT_EQ(value, tree.GetRight()->GetValue());
}

TEST(AvlTree, UpdateHeight) {
  int root_expected_height = 2;
  int root_key = 1;
  int root_value = 2;
  int right_key = 2;
  int right_value = 3;
  int list_key = 3;
  int list_value = 4;
  s21::AvlTree<int> root(root_key, root_value);
  root.Insert(&root, right_key, right_value);
  root.Insert(&root, list_key, list_value);
  root.UpdateHeight(&root);
  EXPECT_EQ(root.GetHeight(&root), root_expected_height);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}