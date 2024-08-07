#include <gtest/gtest.h>

#include <set>
#include <string>

#include "../containers/set/set.h"

TEST(set_test, Full_funcTest) {
  s21::set<int> s1;
  s21::set<int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
  EXPECT_TRUE(s1.empty());
}

TEST(set_test, constructor_default) {
  s21::set<int> s1 = {1, 2, 3};
  s21::set<int> s2 = {4, 5};
  // std::cout << "size from test: " << s1.size() << std::endl;
  s1.swap(s2);
  EXPECT_EQ(int(s1.size()), 2);
  EXPECT_TRUE(s1.contains(4));
  s1.clear();
  EXPECT_EQ(int(s1.size()), 0);
  EXPECT_TRUE(s1.empty());
}

TEST(set_test, Erase) {
  s21::set<int> s{1, 0};
  s21::set<int>::iterator it1 = s.begin();
  s.erase(it1);
  it1 = s.end();
  EXPECT_TRUE(s.contains(1));
  EXPECT_EQ(*it1, 0);
}

TEST(set_test, Find) {
  s21::set<int> s{1, 2, 3};
  s21::set<int>::iterator it1 = s.find(2);
  EXPECT_EQ(*it1, 2);
}