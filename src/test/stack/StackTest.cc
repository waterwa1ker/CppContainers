#include <gtest/gtest.h>

#include "../../containers/stack/Stack.h"

TEST(Stack, Constructor) {
  s21::Stack<int> stack;
  EXPECT_EQ(stack.size(), 0);
  EXPECT_EQ(stack.GetCapacity(), INITIAL_CAPACITY);
}