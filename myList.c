#include "myList.h"

// add to the top of the list
int addNode(Node** head, Doc value){
  // TODO: проверка входа
  Node* tmpNode = (Node*) malloc(sizeof(Node));
  // TODO: проверка малока

  tmpNode->next = *head;
  tmpNode->value = value;
  *head = tmpNode;

  return 0;
}

Node* initNode (Doc value){
  Node* head = (Node*) malloc(sizeof(Node));
  // TODO:: check malloc
  head->next = NULL;
  head->value = value;
  return head;
}

int delNode(Node** head){
  Node* prev = NULL;

  while ((*head)->next) {
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }
  free(*head);

  return 0;
}
