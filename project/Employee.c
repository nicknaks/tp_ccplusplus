#include "Employee.h"

int scan_employee_from_file(FILE *file, Employee* person) {
  if (person == NULL || file == NULL){
    return EXIT_FAILURE;
  }

  char buf [30];

  // read surname
  fscanf(file, "%s", buf);
  person->surname = (char *) malloc(strlen(buf) + 1);
  if (person->surname == NULL) {
    return EXIT_FAILURE;
  }
  strncpy(person->surname, buf, strlen(buf) + 1);

  // read name
  fscanf(file, "%s", buf);
  person->name = (char *) malloc(strlen(buf) + 1);
  if (person->name == NULL) {
    return EXIT_FAILURE;
  }
  strncpy(person->name, buf, strlen(buf) + 1);

  fscanf(file, "%s", buf);
  if (strncmp(buf, "Female", sizeof("Female")) == 0) {
    person->gender = Female;
  } else {
    person->gender = Male;
  }

  fscanf(file, "%d", &person->age);

  fscanf(file, "%d", &person->salary);

  fscanf(file, "%d", &person->experience);

  return EXIT_SUCCESS;
}
