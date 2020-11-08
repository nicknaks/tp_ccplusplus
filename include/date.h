#ifndef HW_1__DATE_H_
#define HW_1__DATE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Date{
  int day;
  int month;
  int year;
} Date;

int scan_date(Date* date);
int compare_date(Date* rhs, Date* lhs);
int print_date(Date* date);

#endif //HW_1__DATE_H_