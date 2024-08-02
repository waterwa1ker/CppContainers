#include <gtest/gtest.h>

#include <list>

#include "../containers/list/list.h"

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

TEST(S21ListAccessIters, end) {
  s21::list<int> val{1, 2, 3};
  std::list<int> check{1, 2, 3};
  EXPECT_EQ(*val.end(), *check.end());
}

TEST(S21ListValuesAccess, empty) {
  s21::list<int> val{1, 2, 3};
  EXPECT_EQ(val.empty(), false);
  s21::list<int> v;
  EXPECT_EQ(v.empty(), true);
}

TEST(S21ListValuesAccess, size) {
  s21::list<int> val{1, 2, 3};
  EXPECT_EQ(val.size(), 3);
  s21::list<int> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(S21ListValuesAccess, max_size) {
  s21::list<int> val{1, 2};
  std::list<int> check{1, 2};
  EXPECT_EQ(val.max_size(), check.max_size());
}

TEST(S21ListModify, clear) {
  s21::list<int> val{1, 2, 3};
  std::list<int> check{1, 2, 3};
  val.clear();
  check.clear();
  EXPECT_EQ(val.size(), check.size());
}

TEST(S21ListModify, insert) {
  s21::list<int> val{1};
  s21::list<int>::iterator it = val.insert(val.begin(), 2);
  EXPECT_EQ(*it, 2);
  EXPECT_EQ(*val.begin(), 2);

  std::list<int> check{1};
  check.insert(check.begin(), 2);
  EXPECT_EQ(*check.begin(), 2);
}

TEST(S21ListModify, erase) {
  s21::list<int> val{1, 2, 3};
  val.erase(val.begin());
  EXPECT_EQ(*val.begin(), 2);

  std::list<int> check{1, 2, 3};
  check.erase(check.begin());
  EXPECT_EQ(*check.begin(), 2);
}

TEST(S21ListModify, push_back) {
  s21::list<int> val;
  val.push_back(1);
  EXPECT_EQ(*val.begin(), 1);
}

TEST(S21ListModify, pop_back) {
  s21::list<int> val{1};
  val.pop_back();
  EXPECT_EQ(val.end(), nullptr);
}

TEST(S21ListModify, push_front) {
  s21::list<int> val;
  val.push_front(1);
  EXPECT_EQ(*val.begin(), 1);
}

TEST(S21ListModify, pop_front) {
  s21::list<int> val{1};
  val.pop_front();
  EXPECT_EQ(val.begin(), nullptr);
  val.push_front(1);
  val.push_front(2);
  EXPECT_EQ(*val.begin(), 2);
  EXPECT_EQ(*(--val.end()), 1);
}

TEST(S21ListModify, swap) {
  s21::list<int> vl1{1, 2, 3};
  s21::list<int> vl2{4, 5, 6};

  std::list<int> ch1{1, 2, 3};
  std::list<int> ch2{4, 5, 6};

  vl1.swap(vl2);
  ch1.swap(ch2);
  EXPECT_EQ(*vl1.begin(), *ch1.begin());
  EXPECT_EQ(*(++vl1.begin()), *(++ch1.begin()));

  EXPECT_EQ(*vl2.begin(), *ch2.begin());
  EXPECT_EQ(*(++vl2.begin()), *(++ch2.begin()));
}

bool comp(s21::list<int> vl, std::list<int> ch) {
  bool eq = false;
  s21::list<int>::iterator tmp_v = vl.begin();
  std::list<int>::iterator tmp_c = ch.begin();
  for (size_t n = 0; n < vl.size() and n < ch.size(); ++n) {
    eq = *tmp_v == *tmp_c;
    if (eq != true) break;
    tmp_v = ++tmp_v;
    tmp_c = ++tmp_c;
  }
  return eq;
}

TEST(S21ListModify, merge) {
  s21::list<int> vl1{1, 2, 3};
  s21::list<int> vl2{4, 5, 6};

  std::list<int> ch1{1, 2, 3};
  std::list<int> ch2{4, 5, 6};

  vl1.merge(vl2);
  ch1.merge(ch2);

  EXPECT_EQ(comp(vl1, ch1), true);
}

TEST(S21ListModify, splice) {
  s21::list<int> vl1{1, 2, 3};
  s21::list<int> vl2{4, 5, 6};

  std::list<int> ch1{1, 2, 3};
  std::list<int> ch2{4, 5, 6};

  vl1.splice(++vl1.begin(), vl2);
  ch1.splice(++ch1.begin(), ch2);

  EXPECT_EQ(comp(vl1, ch1), true);
}

TEST(S21ListModify, reverse) {
  s21::list<int> vl1{1, 2, 3};

  std::list<int> ch1{1, 2, 3};

  vl1.reverse();
  ch1.reverse();

  EXPECT_EQ(comp(vl1, ch1), true);
}

TEST(S21ListModify, unique) {
  s21::list<int> vl1{1, 1, 2, 3, 3, 6};

  std::list<int> ch1{1, 1, 2, 3, 3, 6};

  vl1.unique();
  ch1.unique();

  EXPECT_EQ(comp(vl1, ch1), true);
}

TEST(S21ListModify, sort) {
  s21::list<int> vl1{8, 2, 8, 8, 2, 1, 0, 0};

  std::list<int> ch1{8, 2, 8, 8, 2, 1, 0, 0};

  vl1.sort();
  ch1.sort();

  EXPECT_EQ(comp(vl1, ch1), true);
}

TEST(S21ListIterator, default_construct) {
  s21::list<int>::ListIterator iter;
  EXPECT_EQ(iter.getNode(), nullptr);
}

TEST(S21ListIterator, node_construct) {
  s21::list<int> val{1};

  s21::list<int>::ListIterator iter(val.begin().getNode());
  EXPECT_NE(iter.getNode(), nullptr);
  EXPECT_EQ(*iter, 1);
}

TEST(S21ListIterator, destructor) {
  s21::list<int> val{1};

  s21::list<int>::ListIterator iter(val.begin().getNode());
  iter.~ListIterator();
  EXPECT_EQ(iter.getNode(), nullptr);
}

// int main(int argc, char **argv) {
//   testing::InitGoogleTest(&argc, argv);

//   return RUN_ALL_TESTS();
// }