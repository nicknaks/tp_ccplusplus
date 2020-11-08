#include "../include/my_list.h"

enum Commands{
  ADD_DOCUMENT = 1,
  PRINT_DOCUMENT
};

int menu(Node **list_docs);

int main() {
  Node *list_docs = NULL;

  int function_result = 0;

  function_result = menu(&list_docs);
  if (function_result == EXIT_FAILURE) {
    del_node(&list_docs);
    return EXIT_FAILURE;
  }

  del_node(&list_docs);
  return EXIT_SUCCESS;
}

int menu(Node **list_docs) {
  if (list_docs == NULL) {
    return EXIT_FAILURE;
  }

  int function_result = 0;
  int command = 0;

  do {
    Doc document = {NULL, NULL, NULL, {-1, -1, -1}, {-1, -1, -1}, 0};
    printf("%s", "MENU\n1 - Add new document\t 2 - Print documents\t 3 - Exit\nEnter : ");
    scanf("%d", &command);

    switch (command) {
      case ADD_DOCUMENT:
        function_result = scan_doc(&document, 'W');
        if (function_result == EXIT_FAILURE) {
          return EXIT_FAILURE;
        }

        if (*list_docs == NULL) {
          *list_docs = init_node(&document);

          if (list_docs == NULL) {
            return EXIT_FAILURE;
          }
        } else {
          function_result = add_node(list_docs, &document);
          if (function_result == EXIT_FAILURE){
            return EXIT_FAILURE;
          }
        }
        break;

      case PRINT_DOCUMENT:
        printf("If you want to pass any field, enter -1\n");

        function_result = scan_doc(&document, 'P');
        if (function_result == EXIT_FAILURE) {
          return EXIT_FAILURE;
        }

        function_result = find_documents(*list_docs, &document);
        if (function_result == -1){
          return EXIT_FAILURE;
        }

        break;

      default:
        command = 3;
        break;
    }
  } while (command != 3);
  return EXIT_SUCCESS;
}
