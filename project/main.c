
#include "my_list/List.h"
#include <stdio.h>

int main() {
  Node* employee = NULL;
  char* filename = "../employee.dat";
  scan_from_file(filename, &employee);

  separate_and_print_node(employee);

  free_node(&employee);
}
