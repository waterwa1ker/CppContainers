#include <gtest/gtest.h>

#include <vector>

#include "../containers/vector/vector.h"

TEST(S21VectorConsturcts, Default) {
  s21::vector<int> val;
  EXPECT_EQ(val.size(), 0);
  EXPECT_EQ(val.capacity(), 0);
  EXPECT_EQ(val.begin(), nullptr);
}

TEST(S21VectorConsturcts, Size) {
  s21::vector<int> val(2);
  EXPECT_EQ(val.size(), 2);
  EXPECT_EQ(val.capacity(), 2);
  EXPECT_NE(val.begin(), nullptr);
}

TEST(S21VectorConsturcts, Initilizer_list) {
  s21::vector<int> val{1, 2};
  EXPECT_EQ(val.size(), 2);
  EXPECT_EQ(val.capacity(), 2);
  EXPECT_EQ(*val.begin(), 1);
}

TEST(S21VectorConsturcts, Move) {
  s21::vector<int> val(s21::vector<int>{1, 2});
  EXPECT_EQ(val.size(), 2);
  EXPECT_EQ(val.capacity(), 2);
  EXPECT_EQ(*val.begin(), 1);
}

TEST(S21VectorConsturcts, Copy) {
  s21::vector<int> val{1, 2};
  s21::vector<int> val2(val);
  EXPECT_EQ(val.size(), 2);
  EXPECT_EQ(val.capacity(), 2);
  EXPECT_EQ(*val.begin(), 1);
  EXPECT_EQ(val2.size(), 2);
  EXPECT_EQ(val2.capacity(), 2);
  EXPECT_EQ(*val2.begin(), 1);
}

TEST(S21VectorConsturcts, Destructor) {
  s21::vector<int> val(s21::vector<int>{1, 2});
  val.~vector();
  EXPECT_EQ(val.size(), 0);
  EXPECT_EQ(val.capacity(), 0);
  EXPECT_EQ(val.begin(), nullptr);
}

TEST(S21VectorConsturcts, MoveOperator) {
  s21::vector<int> val = s21::vector<int>{1, 2};
  EXPECT_EQ(val.size(), 2);
  EXPECT_EQ(val.capacity(), 2);
  EXPECT_EQ(*val.begin(), 1);
}

TEST(S21VectorMethods, At) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val.at(1), che.at(1));
}

TEST(S21VectorMethods, OperatorSq) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val[1], che[1]);
}

TEST(S21VectorMethods, Front) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val.front(), che.front());
}

TEST(S21VectorMethods, Back) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val.back(), che.back());
}

TEST(S21VectorMethods, Data) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(*val.data(), *che.data());
}

TEST(S21VectorMethods, Begin) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(*val.begin(), *che.begin());
}

TEST(S21VectorMethods, End) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_NE(val.end(), nullptr);
}

TEST(S21VectorMethods, Empty) {
  s21::vector<int> val{1, 2};
  EXPECT_EQ(val.empty(), false);
}

TEST(S21VectorMethods, Size) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val.size(), che.size());
}

TEST(S21VectorMethods, Max_Size) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val.max_size(), che.max_size());
}

TEST(S21VectorMethods, Reserve) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  val.reserve(3);
  che.reserve(3);
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(val.capacity(), che.capacity());
  EXPECT_EQ(*val.begin(), *che.begin());
}

TEST(S21VectorMethods, Capacity) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(val.capacity(), che.capacity());
}

TEST(S21VectorMethods, Shrink_to_fit) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  val.shrink_to_fit();
  che.shrink_to_fit();
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(val.capacity(), che.capacity());
  EXPECT_EQ(*val.begin(), *che.begin());
}

TEST(S21VectorMethods, Clear) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  val.clear();
  che.clear();
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(val.capacity(), che.capacity());
}

TEST(S21VectorMethods, Insert) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  EXPECT_EQ(*(val.insert(val.begin(), 3)), *(che.insert(che.begin(), 3)));
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(*val.begin(), *che.begin());
}

TEST(S21VectorMethods, Erase) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  val.erase(val.begin());
  che.erase(che.begin());
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(*val.begin(), *che.begin());
}

TEST(S21VectorMethods, Push_back) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  val.push_back(3);
  che.push_back(3);
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(val[2], che[2]);
}

TEST(S21VectorMethods, Pop_back) {
  s21::vector<int> val{1, 2};
  std::vector<int> che{1, 2};
  val.pop_back();
  che.pop_back();
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(val[0], che[0]);
}

TEST(S21VectorMethods, Swap) {
  s21::vector<int> val{1, 2};
  s21::vector<int> val2{3, 4, 5};
  std::vector<int> che{1, 2};
  std::vector<int> che2{3, 4, 5};
  val.swap(val2);
  che.swap(che2);
  EXPECT_EQ(val.size(), che.size());
  EXPECT_EQ(val[0], che[0]);
}
