#include <gtest/gtest.h>

#include "../../containers/tree/AvlTreeIterator.h"

TEST(AvlTreeIterator, HasNextFalse) {
  s21::AvlTreeIterator<int> iterator(nullptr);
  EXPECT_FALSE(iterator.hasNext());
}

TEST(AvlTreeIterator, HasNextTrue) {
  s21::AvlTree<int> tree(2, 3);
  s21::AvlTreeIterator<int> iterator(&tree);
  EXPECT_TRUE(iterator.hasNext());
}