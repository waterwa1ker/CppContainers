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

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}