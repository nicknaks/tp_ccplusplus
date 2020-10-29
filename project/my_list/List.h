#ifndef HW2_PROJECT_MY_LIST_LIST_H_
#define HW2_PROJECT_MY_LIST_LIST_H_

#include "../my_array/Array.h"

typedef struct Node{
  struct Node* next;
  char* position; // worker position
  Array* employees; // all workers by position
} Node;

// инициализации и удаление
Node* init_node(const char* position);
int free_node(Node **head);

int print_node(const Node* head);

// добавление нового сотрудника
Array* find_node(const Node *head, const char* position);
Array* add_node(Node **head, const char* position);

// чтение из файла
int scan_from_file(const char *filename, Node** head);

#endif //HW2_PROJECT_MY_LIST_LIST_H_
