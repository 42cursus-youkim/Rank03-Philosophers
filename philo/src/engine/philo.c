#include "philo.h"
#include <string.h>

void *p_function(void * data);

int main(void)
{
  pthread_t pthread;
  int id;
//   int status;
  char p1[] = "thread_created";
  char p2[] = "thread_main";

  id = pthread_create(&pthread, NULL, p_function, (void*)p1);
  if(id < 0)
  {
    printf("pthread0 create error\n");
    exit(EXIT_FAILURE);
  }

  p_function((void *)p2);

  printf("created thread id: %x\n", id);
  printf("end\n");
  return 0;
}

void *p_function(void * data)
{
  pthread_t tid; // thread id

  tid = pthread_self();

  char* thread_name = (char *)data;
  int i = 0;

  while(i < 3)
  {
    printf("<%s> tid : %x\n", thread_name, (unsigned int)tid);
    i++;
    usleep(1000 * 1000);
  }
  return (NULL);
}
