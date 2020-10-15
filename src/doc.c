#include "../include/doc.h"

// choose : 'P' - to scan doc with pass fields
// choose : 'W' - to scan doc without pass any field
int scan_doc(Doc *document, char choose) {
  if (document == NULL){
    return EXIT_FAILURE;
  }

  char buf[30];

  printf("%s", "Enter organization name : ");
  scanf("%29s", buf);

  if (choose == 'P' && buf[0] == '-' && buf[1] == '1') {
    document->organization = NULL;
  } else {
    document->organization = (char *) malloc(strlen(buf) + 1);
    if (document->organization == NULL){
      return EXIT_FAILURE;
    }
    strncpy(document->organization, buf, strlen(buf) + 1);
  }

  printf("%s", "Enter document type : ");
  scanf("%29s", &buf);

  if (choose == 'P' && buf[0] == '-' && buf[1] == '1') {
    document->type = NULL;
  } else {
    document->type = (char *) malloc(strlen(buf) + 1);
    if (document->type == NULL){
      return EXIT_FAILURE;
    }

    strncpy(document->type, buf, strlen(buf) + 1);
  }

  printf("%s", "Enter english name : ");
  scanf("%29s", &buf);

  if (choose == 'P' && buf[0] == '-' && buf[1] == '1') {
    document->name = NULL;
  } else {
    document->name = (char *) malloc(strlen(buf) + 1);

    if (document->name == NULL){
      return EXIT_FAILURE;
    }
    strncpy(document->name, buf, strlen(buf) + 1);
  }

  int field_choose = 0;

  printf("%s", "\tAdoption date\n");
  if (choose == 'P') {
    printf("%s", "If you want to skip this field, enter '-1' : ");
    scanf("%d", &field_choose);
  }

  int function_result = 0;

  if (choose == 'W' || field_choose != -1) {
    function_result = scan_date(&document->adoption_date);

    if (function_result == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }

  printf("%s", "\tEntry date\n");
  if (choose == 'P') {
    printf("%s", "If you want to skip this field, enter '-1' : ");
    scanf("%d", &field_choose);
  }

  if (choose == 'W' || field_choose != -1) {
    function_result = scan_date(&document->entry_date);

    if (function_result == EXIT_FAILURE) {
      return EXIT_FAILURE;
    }
  }

  int rus_lang = 0;

  if (choose == 'P') {
    document->rus_lang = false;
    return EXIT_SUCCESS;
  }

  printf("%s", "Does the Russian language support (if support, enter 1) : ");
  scanf("%d", &rus_lang);

  if (rus_lang == 1) {
    document->rus_lang = true;
  } else {
    document->rus_lang = false;
  }
  printf("%s", "SUCCESS : add new document\n");

  return EXIT_SUCCESS;
}

int print_document(Doc *document) {
  if (document == NULL) {
    return EXIT_FAILURE;
  }

  printf("%s || %s || %s || ", document->name, document->type, document->organization);
  print_date(&document->entry_date);

  printf(" || ");
  print_date(&document->adoption_date);

  if (document->rus_lang == true) {
    printf(" || Support\n");
  } else {
    printf(" || Doesn't Support\n");
  }

  return EXIT_SUCCESS;
}
