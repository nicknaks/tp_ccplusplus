#include "date.h"


int scan_date(Date *date) {
  printf("%s", "Enter day : ");
  scanf("%d", &date->day);

  printf("%s", "Enter month :");
  scanf("%d", &date->month);

  printf("%s", "Enter  year : ");
  scanf("%d", &date->year);

  return 0;
}

int compare_date(Date *rhs, Date *lhs) {
  return rhs->day == lhs->day && rhs->month == lhs->month && rhs->year == lhs->year;
}

int print_date(Date *date) {
  printf("%d/%d/%d", date->day, date->month, date->year);
  return 0;
}
