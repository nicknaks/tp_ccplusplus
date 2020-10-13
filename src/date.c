#include "../include/date.h"


int scan_date(Date *date) {
  if (date == NULL){
    return -1;
  }

  int tmp;

  printf("%s", "Enter day : ");
  scanf("%d", &tmp);

  if (tmp >= 1 && tmp <= 31) {
    date->day = tmp;
  } else {
    date->day = 0;
  }

  printf("%s", "Enter month :");
  scanf("%d", &tmp);

  if (tmp >= 1 && tmp <= 12) {
    date->month = tmp;
  } else {
    date->month = 0;
  }

  printf("%s", "Enter  year : ");
  scanf("%d", &tmp);
  if (tmp >= 1) {
    date->year = tmp;
  } else {
    date->year = 0;
  }

  return 0;
}

int compare_date(Date *rhs, Date *lhs) {
  if (rhs == NULL || lhs == NULL) {
    return -1;
  }
  return rhs->day == lhs->day && rhs->month == lhs->month && rhs->year == lhs->year;
}

int print_date(Date *date) {
  if (date == NULL) {
    return -1;
  }

  printf("%d/%d/%d", date->day, date->month, date->year);
  return 0;
}
