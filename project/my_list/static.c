#include "List.h"

int separate_and_print_node(const Node *head) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }

  Node* change_head = (Node*) head;

  do {
    printf("\n\tPosition : %s\n", change_head->position);
    split_arrays(change_head->employees);
    change_head = change_head->next;
  } while (change_head != NULL);
  return EXIT_SUCCESS;
}
