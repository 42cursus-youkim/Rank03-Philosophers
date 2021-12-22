#include "philo.h"

t_res	new_thread(pthread_t *pthread, routine func, void *arg)
{
	const t_res	res = pthread_create(pthread, NULL, func, arg);

	if (res == OK)
		return (res);
	printf("Error: could not create thread\n");
	exit(EXIT_FAILURE);
}

void	*p_function(void *data)
{
	pthread_t tid; // thread id

	tid = pthread_self();

	char* thread_name = data;
	int i = -1;

	while(++i < 3)
	{
		printf("<%s> tid : %x (%d/%d)\n",
			thread_name, (unsigned int)tid, i, 3);
		usleep(1000 * 1000);
	}
	return ((void *)12345);
}
