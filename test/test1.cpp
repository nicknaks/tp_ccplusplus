#include "lib/googletest/include/gtest/gtest.h"

extern "C" {
  #include "../project/my_list/List.c"
}

TEST(InitListTest, InvalidPositionName) {
  ASSERT_EQ(init_node(NULL), nullptr);
}

TEST(InitListTest1, InvalidPositionName) {
  ASSERT_EQ(init_node(NULL), nullptr);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}