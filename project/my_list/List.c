#include <string.h>
#include "List.h"

Node *init_node(const char* position) {
  if (position == NULL) {
    return NULL;
  }

  Node *head = (Node *) calloc(1, sizeof(Node));
  if (head == NULL) {
    return NULL;
  }

  head->next = NULL;

  head->position = (char *) calloc(strlen(position) + 1, sizeof(char));
  if (head->position == NULL) {
    free(head);
    return NULL;
  }
  strncpy(head->position, position, strlen(position) + 1);

  head->employees = init_array();

  return head;
}

int free_node(Node **head) {
  if (*head == NULL) {
    return EXIT_FAILURE;
  }

  Node *prev = NULL;

  while ((*head)->next) {
    prev = (*head);
    (*head) = (*head)->next;
    free_array(prev->employees);
    free(prev->position);
    free(prev);
  }

  free_array((*head)->employees);
  free((*head)->position);

  free(*head);

  return EXIT_SUCCESS;
}


Array* add_node(Node **head, const char* position) {
  if (*head == NULL || position == NULL) {
    return NULL;
  }

  Node *tmp_node = (Node *) calloc(1, sizeof(Node));
  if (tmp_node == NULL) {
    return NULL;
  }

  tmp_node->next = *head;
  tmp_node->position = (char *) calloc(strlen(position) + 1, sizeof(char));

  if (tmp_node->position == NULL) {
    return NULL;
  }
  strncpy(tmp_node->position, position, strlen(position) + 1);

  tmp_node->employees = init_array();
  if (tmp_node->employees == NULL) {
    return NULL;
  }

  *head = tmp_node;
  return (*head)->employees;
}
Array* find_node(const Node* head, const char* position) {
  if (head == NULL || position == NULL) {
    return NULL;
  }

  Node* change_head = (Node*) head;

  do {
    if (strncmp(change_head->position, position, strlen(position)) == 0){
      return change_head->employees;
    }
    change_head = change_head->next;

  } while(change_head != NULL);

  return NULL;
}


int scan_from_file(const char *filename, Node** head) {
  if (head == NULL || filename == NULL) {
    return EXIT_FAILURE;
  }

  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    puts("ERROR : FILE OPEN");
    return EXIT_FAILURE;
  }

  char buff_scan [30];

  while (fscanf(file,"%29s",buff_scan) != EOF) {
    Array* employees = NULL;
    Employee person;
    if (*head == NULL) {
      *head = init_node(buff_scan);
      employees = (*head)->employees;
    } else {
      employees = find_node(*head, buff_scan);
      if (employees == NULL) {
        employees = add_node(head, buff_scan);
      }
    }

    scan_employee_from_file(file, &person);
    add_element(employees, &person);
  }

  fclose(file);
  return EXIT_SUCCESS;
}














