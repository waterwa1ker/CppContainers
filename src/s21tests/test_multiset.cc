#include <gtest/gtest.h>

#include "../containers/multiset/multiset.h"

TEST(multiset_test, constructor_default) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(multiset_test, init_constructor) {
  s21::multiset<int> s21_multiset{4, 1, 5, 3};
  std::multiset<int> std_multiset{4, 1, 5, 3};
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();
  bool result = true;
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, copy_constructor) {
  s21::multiset<int> s21_multiset{6, 2};
  std::multiset<int> std_multiset{6, 2};
  s21::multiset<int> s21_copy(s21_multiset);
  std::multiset<int> std_copy(std_multiset);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  auto s21_iterator = s21_copy.begin();
  auto std_iterator = std_copy.begin();
  bool result = true;
  for (size_t i = 0; i < s21_copy.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, copy_constructor_empty) {
  s21::multiset<int> s21_multiset;
  s21::multiset<int> s21_copy(s21_multiset);
  std::multiset<int> std_multiset;
  std::multiset<int> std_copy(std_multiset);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  auto s21_iterator = s21_copy.begin();
  auto std_iterator = std_copy.begin();
  bool result = true;
  for (size_t i = 0; i < s21_copy.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, move_constructor) {
  s21::multiset<int> s21_multiset{1, 2, 3};
  s21::multiset<int> s21_copy(s21_multiset);
  s21::multiset<int> s21_move(std::move(s21_multiset));
  std::multiset<int> std_multiset{1, 2, 3};
  std::multiset<int> std_copy(std_multiset);
  std::multiset<int> std_move(std::move(std_multiset));
  EXPECT_EQ(s21_move.size(), std_move.size());
  auto s21_iterator = s21_move.begin();
  auto std_iterator = std_move.begin();
  bool result = true;
  for (size_t i = 0; i < s21_move.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, move_constructor_empty) {
  s21::multiset<int> s21_multiset;
  s21::multiset<int> s21_copy(s21_multiset);
  s21::multiset<int> s21_move(std::move(s21_multiset));
  std::multiset<int> std_multiset;
  std::multiset<int> std_copy(std_multiset);
  std::multiset<int> std_move(std::move(std_multiset));
  EXPECT_EQ(s21_move.size(), std_move.size());
  auto s21_iterator = s21_move.begin();
  auto std_iterator = std_move.begin();
  bool result = true;
  for (size_t i = 0; i < s21_move.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, begin) {
  s21::multiset<int> s21_multiset{5, 6, 2};
  std::multiset<int> std_multiset{5, 6, 2};
  EXPECT_EQ(*s21_multiset.begin(), *std_multiset.begin());
}

TEST(multiset_test, end_empty) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(*s21_multiset.end(), *std_multiset.end());
}

TEST(multiset_test, empty) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(multiset_test, not_empty) {
  s21::multiset<int> s21_multiset{1, 22};
  std::multiset<int> std_multiset{1, 22};
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(multiset_test, max_size) {
  s21::multiset<double> s21_multiset{1};
  std::multiset<double> std_multiset{1};
  // EXPECT_EQ(s21_multiset.max_size(), std_multiset.max_size());
}

TEST(multiset_test, clear) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};
  s21_multiset.clear();
  std_multiset.clear();
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();
  bool result = true;
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, insert) {
  s21::multiset<int> s21_multiset{1, 9999, 20000};
  s21_multiset.insert(5);
  std::multiset<int> std_multiset{1, 9999, 20000};
  std_multiset.insert(5);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();
  bool result = true;
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, insert_empty) {
  s21::multiset<int> s21_multiset;
  s21_multiset.insert(5);
  std::multiset<int> std_multiset;
  std_multiset.insert(5);
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();
  bool result = true;
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, erase_begin) {
  s21::multiset<int> s21_multiset{1, 2, 3};
  s21_multiset.erase(s21_multiset.begin());
  std::multiset<int> std_multiset{1, 2, 3};
  std_multiset.erase(std_multiset.begin());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();
  bool result = true;
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(multiset_test, erase_end) {
  s21::multiset<int> s21_multiset{1, 2, 3};
  auto temp = s21_multiset.begin();
  while (*temp != *s21_multiset.end()) {
    *temp++;
  }
  s21_multiset.erase(temp);
  std::multiset<int> std_multiset{1, 2, 3};
  std_multiset.erase(std_multiset.end().operator--());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();
  bool result = true;
  for (size_t i = 0; i < s21_multiset.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}
/*
TEST(multiset_test, merge) {
  s21::multiset<int> s21_this{1, 46, 234};
  s21::multiset<int> s21_other{50, 357, 6028};
  s21_this.merge(s21_other);
  std::multiset<int> std_this{1, 46, 234};
  std::multiset<int> std_other{50, 357, 6028};
  std_this.merge(std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}
*/