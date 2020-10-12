#include "doc.h"

int scan_doc(Doc *document, char choose) {
  if (document == NULL){
    return -1;
  }

  char buf[50];

  printf("%s", "Enter organization name : ");
  scanf("%s", buf);

  if (choose == 'P' && buf[0] == '-' && buf[1] == '1') {
    document->organization = NULL;
  } else {
    document->organization = (char *) malloc(strlen(buf) + 1);
    strncpy(document->organization, buf, strlen(buf) + 1);
  }

  printf("%s", "Enter document type : ");
  scanf("%s", &buf);

  if (choose == 'P' && buf[0] == '-' && buf[1] == '1') {
    document->type = NULL;
  } else {
    document->type = (char *) malloc(strlen(buf) + 1);
    strncpy(document->type, buf, strlen(buf) + 1);
  }

  printf("%s", "Enter english name : ");
  scanf("%s", &buf);

  if (choose == 'P' && buf[0] == '-' && buf[1] == '1') {
    document->name = NULL;
  } else {
    document->name = (char *) malloc(strlen(buf) + 1);
    strncpy(document->name, buf, strlen(buf) + 1);
  }

  int field_choose = 0;

  printf("%s", "\tAdoption date\n");
  if (choose == 'P') {
    printf("%s", "If you want to skip this field, enter '-1' : ");
    scanf("%d", &field_choose);
  }

  if (choose == 'W' || field_choose != -1) {
    scan_date(&document->adoption_date);
  }

  printf("%s", "\tEntry date\n");
  if (choose == 'P') {
    printf("%s", "If you want to skip this field, enter '-1' : ");
    scanf("%d", &field_choose);
  }

  if (choose == 'W' || field_choose != -1) {
    scan_date(&document->entry_date);
  }

  int rusLang;
  if (choose == 'P') {
    printf("%s", "If you wont to skip Russian language support enter -1 : ");
    scanf("%d", &field_choose);

    if (field_choose == -1) {
      document->rus_lang = -1;
      return 0;
    }
  }

  printf("%s", "Does the Russian language support (if support, enter 1) : ");
  scanf("%d", &rusLang);

  if (rusLang == 1) {
    document->rus_lang = 1;
  } else {
    document->rus_lang = 0;
  }

  if (choose == 'W') {
    printf("%s", "SUCCESS : add new document\n");
  }
  return 0;
}

int print_document(Doc *document) {
  if (document == NULL) {
    return -1;
  }

  printf("%s || %s || %s || ", document->name, document->type, document->organization);
  print_date(&document->entry_date);
  printf(" || ");
  print_date(&document->adoption_date);
  if (document->rus_lang == 1) {
    printf(" || rus_support\n");
  } else {
    printf(" || rus_doesn't_support\n");
  }
  return 0;
}


