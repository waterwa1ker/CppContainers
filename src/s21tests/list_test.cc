#include "../containers/list/list.h"

#include <gtest/gtest.h>

#include <list>

TEST(S21ListConstructs, Default) {
  s21::list<int> l;
  EXPECT_EQ(l.size(), 0);
  EXPECT_EQ(l.begin(), nullptr);
}

TEST(S21ListConstructs, Sizer) {
  s21::list<int> l(3);
  EXPECT_EQ(l.size(), 3);
  EXPECT_NE(l.begin(), nullptr);
}

TEST(S21ListConstructs, Initlist) {
  s21::list<int> l{1, 2};
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(*(l.begin()), 1);
}

TEST(S21ListConstructs, Move) {
  s21::list<int> val(s21::list<int>{1, 2, 3});
  EXPECT_EQ(val.size(), 3);
  EXPECT_EQ(*(val.begin()), 1);
}

TEST(S21ListConstructs, Copy) {
  s21::list<int> ch{1, 2, 3};
  s21::list<int> val(ch);
  EXPECT_EQ(val.size(), 3);
  EXPECT_EQ(*(val.begin()), 1);
  EXPECT_EQ(ch.size(), 3);
  EXPECT_EQ(*(ch.begin()), 1);
}

TEST(S21ListConstructs, Delete) {
  s21::list<int> val{1, 3, 4};
  val.~list();
  EXPECT_EQ(val.size(), 0);
  EXPECT_EQ(val.begin(), nullptr);
  EXPECT_EQ(val.end(), nullptr);
}

TEST(S21ListOperator, EqualSym) {
  s21::list<int> ch{1, 2, 3};
  s21::list<int> val = ch;
  EXPECT_EQ(val.size(), 3);
  EXPECT_EQ(*(val.begin()), 1);
  EXPECT_EQ(ch.size(), 3);
  EXPECT_EQ(*(ch.begin()), 1);
}

TEST(S21ListAccess, front_normal) {
  s21::list<int> val{1, 2, 3};
  std::list<int> check{1, 2, 3};
  EXPECT_EQ(val.front(), check.front());
}

TEST(S21ListAccess, front_err) {
  s21::list<int> val;
  EXPECT_ANY_THROW(val.front(););
}

TEST(S21ListAccess, back_normal) {
  s21::list<int> val{1, 2, 3};
  std::list<int> check{1, 2, 3};
  EXPECT_EQ(val.back(), check.back());
}

TEST(S21ListAccess, back_err) {
  s21::list<int> val;
  EXPECT_ANY_THROW(val.back(););
}

TEST(S21ListAccessIters, begin) {
  s21::list<int> val{1, 2, 3};
  std::list<int> check{1, 2, 3};
  EXPECT_EQ(*val.begin(), *check.begin());
}

// TEST(S21ListAccessIters, end) {
//   s21::list<int> val{1, 2, 3};
//   std::list<int> check{1, 2, 3};
//   EXPECT_EQ(*val.end(), *check.end());
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}