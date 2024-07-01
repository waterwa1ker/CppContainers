#include <gtest/gtest.h>

#include "../../containers/stack/Stack.h"

TEST(Stack, Constructor) {
  s21::Stack<int> stack;
  EXPECT_EQ(stack.size(), 0);
  EXPECT_EQ(stack.GetCapacity(), INITIAL_CAPACITY);
}

TEST(Stack, InitializerListConstructor) {
  s21::Stack<int> stack = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  EXPECT_EQ(stack.size(), 11);
  EXPECT_EQ(stack.GetCapacity(), 20);
}

TEST(Stack, CopyConstructor) {
  int value = 1;
  s21::Stack<int> old_stack;
  old_stack.push(value);
  s21::Stack<int> new_stack(old_stack);
  EXPECT_EQ(new_stack.size(), 1);
  EXPECT_EQ(new_stack.GetData()[0], value);
}

TEST(Stack, MoveConstructor) {
  s21::Stack<int> move_stack;
  move_stack.push(1);
  s21::Stack<int> stack(std::move(move_stack));
  EXPECT_EQ(stack.size(), 1);
}

// TEST(Stack, AssignmentOperator) {
//     s21::Stack<int> stack = {1, 2, 3, 4, 5};
//     s21::Stack<int> new_stack = stack;
//     EXPECT_EQ(new_stack.size(), 5);
// }

TEST(Stack, Push) {
  s21::Stack<float> stack;
  stack.push(1.2);
  EXPECT_EQ(stack.size(), 1);
}

TEST(Stack, PushMoreThan10) {
  s21::Stack<float> stack;
  int size = 0;
  for (int i = 0; i < 11; ++i, ++size) {
    stack.push(i);
  }
  EXPECT_EQ(stack.size(), size);
  EXPECT_EQ(stack.GetCapacity(), INITIAL_CAPACITY * 2);
}

TEST(Stack, Pop) {
  s21::Stack<int> stack;
  stack.push(1);
  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, PopEmpty) {
  s21::Stack<int> stack;
  EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(Stack, Top) {
  double value = 1.1;
  s21::Stack<double> stack;
  stack.push(value);
  EXPECT_EQ(value, stack.top());
}

TEST(Stack, TopEmpty) {
  s21::Stack<int> stack;
  EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(Stack, TopSomeValues) {
  s21::Stack<int> stack;
  for (int i = 0; i < 10; ++i) {
    stack.push(i);
  }
  for (int i = 9; i > -1; --i) {
    EXPECT_EQ(stack.top(), i);
    stack.pop();
  }
}

TEST(Stack, Empty) {
  s21::Stack<int> stack;
  EXPECT_TRUE(stack.empty());
  stack.push(1);
  EXPECT_FALSE(stack.empty());
}

TEST(Stack, Swap) {
  double value1 = 1;
  double value2 = 2;
  s21::Stack<double> stack1;
  s21::Stack<double> stack2;
  stack1.push(value1);
  stack2.push(value2);
  stack2.push(value2);
  stack1.swap(stack2);
  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack2.size(), 1);
}