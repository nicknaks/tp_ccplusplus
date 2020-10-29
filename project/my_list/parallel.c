#include "List.h"

#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* separate_array(void* arg){
  pthread_detach(pthread_self());
  Node* node = (Node*) arg;

  pthread_mutex_lock(&mutex);

  printf("\n\tPosition : %s\n", node->position);

  split_arrays(node->employees);
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int separate_and_print_node(const Node *head) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }

  size_t count = 0;
  Node* change_head = (Node*) head;
  do {
    count++;
    change_head = change_head->next;
  } while(change_head != NULL);

  size_t thread_max = sysconf(_SC_NPROCESSORS_CONF);

  pthread_t* threads = malloc(thread_max * sizeof(pthread_t));

  int err_flag = 0;

  change_head = (Node*) head;

  do {
    for (int i = 0; i < thread_max; ++i) {
      err_flag = pthread_create(&threads[i], NULL, separate_array, change_head);
      if (err_flag == 0) {
        break;
      }
      if (i + 1 == thread_max) {
        i = -1;
      }
    }
    change_head = change_head->next;
  } while (change_head != NULL);

  free(threads);

  pthread_exit(0);
}
