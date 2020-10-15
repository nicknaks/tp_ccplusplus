#include "lib/googletest/include/gtest/gtest.h"

extern "C" {
  #include "../include/my_list.h"
  #include "../src/date.c"
  #include "../src/my_list.c"
  #include "../src/doc.c"
}

TEST(DateTest, CorrectCompareDateTest) {
  Date rhs {10,11,2000};
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(&rhs, &lhs), 1);
}

TEST(DateTest, InvalidCompareDateTest) {
  Date rhs {1,11,2000};
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(&rhs, &lhs), EXIT_SUCCESS);
}

TEST(DateTest, NULLCompareDateTest) {
  Date lhs {10,11,2000};
  ASSERT_EQ(compare_date(NULL, &lhs), EXIT_FAILURE);
}

TEST(MyListTest, AddNode) {
  Doc doc;
  Node* head = init_node(&doc);
  ASSERT_EQ(add_node(&head, &doc), EXIT_SUCCESS);
  del_node(&head);
}

TEST(MyListTest, InvalidAddNode) {
  Doc doc;
  Node* head = NULL;
  ASSERT_EQ(add_node(&head, &doc), EXIT_FAILURE);
  del_node(&head);
}

TEST(FindDocumentTest, Test1) {
  char tmp_a [2];
  tmp_a[0] = 'A';
  tmp_a[1] = 0;

  char tmp_b [2];
  tmp_b[0] = 'B';
  tmp_b[1] = 0;

  char doc_a [2];
  doc_a[0] = 'A';
  doc_a[1] = 0;

  Doc doc1 = {tmp_a, tmp_a, tmp_a, {1,1,1}, {2,2,2}, true};
  Doc doc2 = {tmp_a, tmp_b, tmp_a, {2,1,1},{3,3,3},false};
  Doc doc3 = {tmp_a, tmp_b, tmp_a, {1,1,1},{3,3,3},false};
  Doc doc_search = {tmp_a, NULL, NULL, {1,1,1}, {-1,-1,-1}, false};
  Node* head = init_node(&doc1);
  add_node(&head, &doc2);
  add_node(&head, &doc3);

  ASSERT_EQ(find_documents(head, &doc_search), 2);
  del_node(&head);
}

TEST(FindDocumentTest, Test2) {
  Node* head = NULL;
  Doc* p_doc = NULL;
  ASSERT_EQ(find_documents(head, p_doc), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}