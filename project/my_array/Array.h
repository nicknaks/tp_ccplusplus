//
// Created by Никита on 27.10.2020.
//

#ifndef HW2_PROJECT_MY_ARRAY_ARRAY_H_
#define HW2_PROJECT_MY_ARRAY_ARRAY_H_


#include "../Employee.h"

typedef struct Array {
  size_t capacity;
  size_t size;
  Employee* employee;
  bool is_sorted;
} Array;

Array* init_array();

int add_element(Array* array,const Employee* employee);
int resize(Array* array);

int print_array(const Array* array);
int free_array(Array* array);

int split_arrays(Array* array);

#endif //HW2_PROJECT_MY_ARRAY_ARRAY_H_
