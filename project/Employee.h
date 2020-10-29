
#ifndef HW2_PROJECT_EMPLOYEE_H_
#define HW2_PROJECT_EMPLOYEE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


enum Gender{
  Male,
  Female,
};

typedef struct Employee{
  char* name;
  char* surname;
  enum Gender gender;
  int age;
  int salary;
  int experience;
} Employee;


int scan_employee_from_file(FILE* file, Employee* person);

#endif //HW2_PROJECT_EMPLOYEE_H_
