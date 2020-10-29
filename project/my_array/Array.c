
#include "Array.h"

// базовые функции
Array *init_array() {
  Array* array = (Array*) calloc(1, sizeof(Array));
  if (array == NULL){
    return NULL;
  }

  array->employee = (Employee*) calloc(10, sizeof(Employee));
  if (array->employee == NULL) {
    return NULL;
  }

  array->size = 0;
  array->capacity = 10;
  array->is_sorted = true;
  return array;
}

int add_element(Array *array, const Employee *employee) {
  if (array == NULL || employee == NULL){
    return EXIT_FAILURE;
  }

  if (array->size + 1 == array->capacity) {
    if (resize(array) != EXIT_SUCCESS) {
      return EXIT_FAILURE;
    }
  }

  array->employee[array->size++] = *employee;

  array->is_sorted = false;
  return EXIT_SUCCESS;
}

int print_array(const Array *array) {
  if (array == NULL) {
    return EXIT_FAILURE;
  }

  for (int i = 0; i < array->size; ++i) {
    printf("%s | %s |", array->employee[i].surname, array->employee[i].name);
    if (array->employee[i].gender == Male){
      printf(" Male |");
    } else {
      printf(" Female |");
    }

    printf(" %d | %d | %d |\n", array->employee[i].age, array->employee[i].salary, array->employee[i].experience);
  }

  return EXIT_SUCCESS;
}

// resize memory in 2x
int resize(Array *array) {
  if (array == NULL){
    return EXIT_FAILURE;
  }

  array->employee = (Employee*) realloc(array->employee, array->capacity * 2 * sizeof(Employee));
  if (array->employee == NULL) {
    return EXIT_FAILURE;
  }

  array->capacity *= 2;
  return EXIT_SUCCESS;
}
int free_array(Array *array) {
  if (array == NULL) {
    return EXIT_FAILURE;
  }

  for (int i = 0; i < array->size; ++i) {
    free(array->employee[i].name);
    free(array->employee[i].surname);
  }

  free(array->employee);

  free(array);
  return EXIT_SUCCESS;
}

// for qsort
int compare_by_age(const void * rhs, const void * lhs) {
  return (((Employee*)lhs)->age - ((Employee*)rhs)->age);
}
int compare_by_surname(const void * rhs, const void * lhs) {
  return strcmp(((Employee*)rhs)->surname, ((Employee*)lhs)->surname);
}

int split_arrays(Array *array) {
  if (array == NULL) {
    return EXIT_FAILURE;
  }

  if (!array->is_sorted) {
    qsort(array->employee, array->size, sizeof(Employee), compare_by_age);
    array->is_sorted = true;
  }

  if (array->size <= 10) {
    print_array(array);
    return EXIT_SUCCESS;
  }

  Array max_age_array;
  Array min_age_array;
  max_age_array.employee = (Employee*) calloc(5, sizeof(Employee));
  min_age_array.employee = (Employee*) calloc(5, sizeof(Employee));

  max_age_array.size = min_age_array.size = 5;

  for (int i = 0; i < max_age_array.size; ++i) {
    max_age_array.employee[i] = array->employee[i];
    min_age_array.employee[i] = array->employee[array->size - 1 - i];
  }

  qsort(max_age_array.employee, max_age_array.size, sizeof(Employee), compare_by_surname);
  printf("\tOldest\n");
  print_array(&max_age_array);

  qsort(min_age_array.employee, min_age_array.size, sizeof(Employee), compare_by_surname);
  printf("\tYoungest\n");
  print_array(&min_age_array);

  free(max_age_array.employee);
  free(min_age_array.employee);
  return EXIT_SUCCESS;
}
