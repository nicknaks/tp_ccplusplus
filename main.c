#include "my_list.h"

int find_documents(Node *head, Doc *search_document);
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

int find_documents(Node *head, Doc *search_document) {
  if (head == NULL || search_document == NULL) {
    return -1;
  }

  int count = 0;

  do {
    Doc *current_document = &head->value;
    if (search_document->organization == NULL
        || strcmp(search_document->organization, current_document->organization) == 0) {
      if (search_document->type == NULL || strcmp(search_document->type, current_document->type) == 0) {
        if (search_document->name == NULL || strcmp(search_document->name, current_document->name) == 0) {
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
  return 0;
}

