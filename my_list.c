#include "my_list.h"

// add to the top of the list
int add_node(Node** head, Doc value){
  if (*head == NULL) {
    return -1;
  }

  Node* tmp_node = (Node*) malloc(sizeof(Node));
  if (tmp_node == NULL) {
    return -1;
  }

  tmp_node->next = *head;
  tmp_node->value = value;
  *head = tmp_node;

  return 0;
}

Node* init_node (Doc value){
  Node* head = (Node*) malloc(sizeof(Node));
  if (head == NULL) {
    return NULL;
  }

  head->next = NULL;
  head->value = value;
  return head;
}

int del_node(Node** head){
  if (*head == NULL) {
    return -1;
  }

  Node* prev = NULL;

  while ((*head)->next) {
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }

  free(*head);

  return 0;
}
