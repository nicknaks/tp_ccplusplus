#include "../include/my_list.h"

int menu(Node **head);

int main() {
  Node *head = NULL;
  menu(&head);

  del_node(&head);

  return 0;
}

int menu(Node **head) {
  if (head == NULL) {
    return -1;
  }

  int function_result = 0;
  int command = 0;

  do {
    Doc document = {NULL, NULL, NULL, {-1, -1, -1}, {-1, -1, -1}, 0};
    printf("%s", "MENU\n1 - Add new document\t 2 - Print documents\t 3 - Exit\nEnter : ");
    scanf("%d", &command);

    switch (command) {
      case 1:
        function_result = scan_doc(&document, 'W');
        if (function_result != 0) {
          return -1;
        }

        if (head == NULL) {
          *head = init_node(document);

          if (head == NULL) {
            return -1;
          }
        } else {
          function_result = add_node(head, document);
          if (function_result != 0){
            return -1;
          }
        }
        break;

      case 2:
        printf("If you want to pass any field, enter -1\n");

        function_result = scan_doc(&document, 'P');
        if (function_result != 0) {
          return -1;
        }

        function_result = find_documents(*head, &document);
        if (function_result != 0){
          return -1;
        }

        break;

      default:
        command = 3;
        break;
    }
  } while (command == 1 || command == 2);
  return 0;
}
