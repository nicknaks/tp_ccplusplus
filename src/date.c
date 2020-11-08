#include "../include/date.h"


int scan_date(Date *date) {
  if (date == NULL) {
    return EXIT_FAILURE;
  }

  int scan_field = 0;

  printf("%s", "Enter day : ");
  scanf("%d", &scan_field);

  if (scan_field >= 1 && scan_field <= 31) {
    date->day = scan_field;
  } else {
    date->day = 0;
  }

  printf("%s", "Enter month :");
  scanf("%d", &scan_field);

  if (scan_field >= 1 && scan_field <= 12) {
    date->month = scan_field;
  } else {
    date->month = 0;
  }

  printf("%s", "Enter  year : ");
  scanf("%d", &scan_field);
  if (scan_field >= 1) {
    date->year = scan_field;
  } else {
    date->year = 0;
  }

  return EXIT_SUCCESS;
}

int compare_date(Date *rhs, Date *lhs) {
  if (rhs == NULL || lhs == NULL) {
    return EXIT_FAILURE;
  }
  return rhs->day == lhs->day && rhs->month == lhs->month && rhs->year == lhs->year;
}

int print_date(Date *date) {
  if (date == NULL) {
    return EXIT_FAILURE;
  }

  printf("%d/%d/%d", date->day, date->month, date->year);
  return EXIT_SUCCESS;
}
