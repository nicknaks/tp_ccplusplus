#include "../include/my_list.h"

// add to the top of the list
int add_node(Node **head, Doc value) {
  if (*head == NULL) {
    return -1;
  }

  Node *tmp_node = (Node *) malloc(sizeof(Node));
  if (tmp_node == NULL) {
    return -1;
  }

  tmp_node->next = *head;
  tmp_node->value = value;
  *head = tmp_node;

  return 0;
}

Node *init_node(Doc value) {
  Node *head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    return NULL;
  }

  head->next = NULL;
  head->value = value;
  return head;
}

int del_node(Node **head) {
  if (*head == NULL) {
    return -1;
  }

  Node *prev = NULL;

  while ((*head)->next) {
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }

  free(*head);

  return 0;
}

int find_documents(Node *head, Doc *search_document) {
  if (head == NULL || search_document == NULL) {
    return -1;
  }

  int count = 0;

  do {
    Doc *current_document = &head->value;
    if (search_document->organization == NULL
        || strncmp(search_document->organization, current_document->organization, strlen(search_document->organization))
            == 0) {
      if (search_document->type == NULL
          || strncmp(search_document->type, current_document->type, strlen(search_document->type)) == 0) {
        if (search_document->name == NULL
            || strncmp(search_document->name, current_document->name, strlen(search_document->name)) == 0) {
          if (search_document->entry_date.day == -1
              || compare_date(&search_document->entry_date, &current_document->entry_date)) {
            if (search_document->adoption_date.day == -1
                || compare_date(&search_document->adoption_date, &current_document->adoption_date)) {
              if (search_document->rus_lang == -1 || search_document->rus_lang == current_document->rus_lang) {
                print_document(current_document);
                count++;
              }
            }
          }
        }
      }

    }
    head = head->next;
  } while (head != NULL);

  if (count == 0) {
    printf("Not Found!");
  }
  return count;
}
