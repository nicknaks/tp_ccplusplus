#ifndef HW_1__MYLIST_H_
#define HW_1__MYLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Date{
  int day;
  int month;
  int year;
} Date;

typedef struct Doc{
  char* organization;
  char* type;
  char* name;
  Date adoptionDate;
  Date entryDate;
  short rusLang; // true or false
} Doc;

typedef struct Node{
  Doc value;
  struct Node* next;
} Node;

int addNode(Node** head, Doc value);

Node* initNode (Doc value);

int delNode(Node** head);

#endif //HW_1__MYLIST_H_