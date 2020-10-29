#include "List.h"

#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* separate_array(void* arg){
  pthread_detach(pthread_self());
  Node* node = (Node*) arg;

  int s = pthread_mutex_lock(&mutex);
  if (s == 0){

  }

  printf("\n\tPosition : %s\n", node->position);

  split_arrays(node->employees);
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int print_node(const Node *head) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }

  size_t count = 0;
  Node* change_head = (Node*) head;
  do {
    count++;
    change_head = change_head->next;
  } while(change_head != NULL);


  // находим кол-во доступных потоков
  size_t thread_max = sysconf(_SC_NPROCESSORS_CONF);
  thread_max = count;

  // создаем потоки
  pthread_t threads [thread_max];

  int err_flag = 0;
  // создаем н - 1 потоков
  // в цикле запускаем все потоки и смотрим, на завершенность всех потоков, постоянно передавая им новые данные

  change_head = (Node*) head;

  size_t i = 0;
  do{

    err_flag = pthread_create(&threads[i], NULL, separate_array, change_head);
    if (err_flag == 0) {
    }
    i++;
    change_head = change_head->next;
  } while (change_head != NULL);

//  do {
//    split_arrays(change_head->employees);
//    change_head = change_head->next;
//  } while (change_head != NULL);
  pthread_exit(0);
 return EXIT_SUCCESS;
}
