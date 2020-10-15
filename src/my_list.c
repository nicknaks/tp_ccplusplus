#include "../include/my_list.h"

int add_node(Node **head, Doc* value) {
  if (*head == NULL || value == NULL) {
    return EXIT_FAILURE;
  }

  Node *tmp_node = (Node *) malloc(sizeof(Node));
  if (tmp_node == NULL) {
    return EXIT_FAILURE;
  }

  tmp_node->next = *head;
  tmp_node->value = *value;
  *head = tmp_node;

  return EXIT_SUCCESS;
}

Node *init_node(Doc* value) {
  if (value == NULL) {
    return NULL;
  }

  Node *head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    return NULL;
  }

  head->next = NULL;
  head->value = *value;
  return head;
}

int del_node(Node **head) {
  if (*head == NULL) {
    return EXIT_FAILURE;
  }

  Node *prev = NULL;

  while ((*head)->next) {
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }

  free(*head);

  return EXIT_SUCCESS;
}

int find_documents(Node *list_docs, Doc *search_document) {
  if (list_docs == NULL || search_document == NULL) {
    return -1;
  }

  int count = 0;

  do {
    Doc *current_document = &list_docs->value;
    if ((search_document->organization == NULL
        || strncmp(search_document->organization, current_document->organization, strlen(search_document->organization))
            == 0) && (search_document->type == NULL
        || strncmp(search_document->type, current_document->type, strlen(search_document->type)) == 0)
        && (search_document->name == NULL
            || strncmp(search_document->name, current_document->name, strlen(search_document->name)) == 0)
        && (search_document->entry_date.day == -1
            || compare_date(&search_document->entry_date, &current_document->entry_date))
        && (search_document->adoption_date.day == -1
            || compare_date(&search_document->adoption_date, &current_document->adoption_date))) {
      count++;

      if (count == 1) {
        printf("Name || Type || Organization || Entry Date || Adoption Date || Russian language\n");
      }

      print_document(current_document);
    }
    list_docs = list_docs->next;
  } while (list_docs != NULL);

  if (count == 0) {
    printf("Not Found!");
  }

  return count;
}
