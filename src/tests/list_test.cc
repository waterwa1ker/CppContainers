#include "../containers/list/list.h"

#include <gtest/gtest.h>

TEST(S21ListConstructs, Default) {
  s21::list<int> l;
  EXPECT_EQ(l.size(), 0);
  EXPECT_EQ(*l, nullptr);
}

TEST(S21ListConstructs, sizer) {
  s21::list<int> l(3);
  EXPECT_EQ(l.size(), 3);
  EXPECT_NE(*l, nullptr);
}

TEST(S21ListConstructs, initlist) {
  s21::list<int> l{1, 2};
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(*l, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}