#ifndef HW_1__MY_LIST_H_
#define HW_1__MY_LIST_H_

#include "doc.h"

typedef struct Node{
  Doc value;
  struct Node* next;
} Node;

int add_node(Node** head, Doc value);

Node* init_node(Doc value);

int del_node(Node** head);

int find_documents(Node *head, Doc *search_document);

#endif //HW_1__MY_LIST_H_