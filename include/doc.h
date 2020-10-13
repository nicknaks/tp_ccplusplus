#ifndef HW_1__DOC_H_
#define HW_1__DOC_H_

#include <stdlib.h>
#include <string.h>

#include "date.h"

typedef struct Doc{
  char* organization;
  char* type;
  char* name;
  Date adoption_date;
  Date entry_date;
  short rus_lang; // true or false
} Doc;

int scan_doc(Doc* document, char choose);
int print_document(Doc* document);

#endif //HW_1__DOC_H_
