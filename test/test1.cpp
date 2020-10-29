#include "googletest/googletest/include/gtest/gtest.h"

extern "C" {
  #include "../project/my_list/List.c"
  #include "../project/my_array/Array.c"
}

TEST(ArrayTests, AddInvalidElement1) {
  ASSERT_EQ(add_element(NULL,NULL), EXIT_FAILURE);
}


TEST(ArrayTests, Resize) {
  Array* array = init_array();
  resize(array);
  EXPECT_EQ(array->capacity, 20);
  free_array(array);
}


TEST(InitListTest, InvalidPositionName) {
  ASSERT_EQ(init_node(NULL), nullptr);
}

TEST(InitListTest1, InvalidPositionName) {
  ASSERT_EQ(init_node(NULL), nullptr);
}

TEST(MainTest, ReadFromFile) {
  ASSERT_EQ(init_node(NULL), nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}