#include "philo.h"

int	new_thread(pthread_t *pthread, routine func, void *arg)
{
	const int id = pthread_create(&pthread, NULL, func, arg);

	if (id <= ERR)
	{
		printf("Error: could not create thread\n");
		exit(EXIT_FAILURE);
	}
}