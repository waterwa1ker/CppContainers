#include "../../set/Set.h"
#include <gtest/gtest.h>

TEST(Set, DefaultConstructor) {
    Set set();
    EXPECT_TRUE(set.GetRoot() == nullptr);
}

TEST(Set, Empty) {
    Set set();
    EXPECT_TRUE(set.empty());
}