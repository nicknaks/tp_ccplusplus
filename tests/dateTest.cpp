#include "lib/googletest/include/gtest/gtest.h"
extern "C" {
  #include "../date.h"
  #include "../date.c"
}

TEST(DateTest, CorrectCompareDateTest) {
  Date rhs {10,11,2000};
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(&rhs, &lhs), 1);
}

TEST(DateTest, InvalidCompareDateTest) {
  Date rhs {1,11,2000};
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(&rhs, &lhs), 0);
}

TEST(DateTest, NULL1CompareDateTest) {
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(NULL, &lhs), -1);
}

TEST(DateTest, NULL2CompareDateTest) {
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(&lhs, NULL), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}