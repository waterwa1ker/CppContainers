#include "../containers/list/list.h"

#include <gtest/gtest.h>

TEST(S21ListConstructs, Default) {
  s21::list<int> l;
  EXPECT_EQ(l.size(), 0);
  EXPECT_EQ(*l, nullptr);
}