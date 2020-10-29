
#include "project/my_list/List.h"
#include <stdio.h>
#include <unistd.h>

int main() {
  Node* head = NULL;
  char* filename = "../employee.dat";
  scan_from_file(filename, &head);

  print_node(head);

  free_node(&head);

//  int a = sysconf(_SC_NPROCESSORS_CONF);
//  printf("%d", a);
}
