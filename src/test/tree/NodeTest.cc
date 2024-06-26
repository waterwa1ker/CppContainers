#include <gtest/gtest.h>

#include "../../containers/tree/Node.h"

TEST(Node, Constructor) {
  int key = 1;
  int value = 2;
  s21::Node<int> node(key, value);
  EXPECT_EQ(key, node.GetKey());
  EXPECT_EQ(value, node.GetValue());
}

TEST(Node, Insert) {
  int key = 1;
  int value = 2;
  int right_key = 3;
  int right_value = 4;
  int left_key = -1;
  int left_value = -2;
  s21::Node<int> node(key, value);
  node.Insert(&node, right_key, right_value);
  node.Insert(&node, left_key, left_value);
  EXPECT_TRUE(right_value == node.GetRight()->GetValue());
  EXPECT_TRUE(left_value == node.GetLeft()->GetValue());
}

TEST(Node, GetMax) {
  s21::Node<int> node;
  int min_key = 1;
  int max_key = 2;
  int min_value = 0;
  int max_value = 3;
  s21::Node<int> max_node(max_key, max_value);
  node.Insert(&node, max_key, max_value);
  node.Insert(&node, min_key, min_value);
  EXPECT_TRUE(max_node == *node.GetMax(node));
}

TEST(Node, GetMin) {
  s21::Node<int> node;
  int min_key = 1;
  int max_key = 2;
  int min_value = 0;
  int max_value = 3;
  s21::Node<int> min_node;
  node.Insert(&node, max_key, max_value);
  node.Insert(&node, min_key, min_value);
  EXPECT_TRUE(min_node == *node.GetMin(node));
}

// TEST(Node, Search) {
//   int right_key = 2;
//   int right_value = 3;
//   int left_key = 1;
//   int left_value = -1;
//   s21::Node<int> node;
//   s21::Node<int> expected_node(left_key, left_value);
//   node.Insert(&node, right_key, right_value);
//   node.Insert(&node, left_key, left_value);
//   EXPECT_TRUE(node.Search(&node, left_key) == nullptr);
// }

// TEST(Node, SearchReturnNull) {
//   int right_key = 2;
//   int right_value = 3;
//   int left_key = 1;
//   int left_value = -1;
//   int random_key = 100;
//   s21::Node<int> node;
//   node.Insert(&node, right_key, right_value);
//   node.Insert(&node, left_key, left_value);
//   EXPECT_TRUE(node.Search(&node, random_key) == nullptr);
// }

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}