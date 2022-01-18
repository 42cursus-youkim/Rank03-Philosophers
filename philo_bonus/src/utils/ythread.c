#include "philosophers.h"

void	init_thread(pthread_t *pthread, t_routine_f func, void *arg)
{
	const int	res = pthread_create(pthread, NULL, func, arg);

	if (res == OK)
		return ;
	yerror("could not initialize thread");
}

void	init_mutex(pthread_mutex_t *mutex)
{
	const int	res = pthread_mutex_init(mutex, NULL);

	if (res == OK)
		return ;
	yerror("could not initialize mutex");
}
