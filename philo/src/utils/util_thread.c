#include "philosophers.h"

t_res	new_thread(pthread_t *pthread, t_routine_f func, void *arg)
{
	const t_res	res = pthread_create(pthread, NULL, func, arg);

	if (res == OK)
		return (res);
	printf("Error: could not create thread\n");
	exit(EXIT_FAILURE);
}

t_res	new_mutex(pthread_mutex_t *mutex)
{
	const t_res	res = pthread_mutex_init(mutex, NULL);

	if (res == OK)
		return (res);
	printf("Error: could not create mutex\n");
	exit(EXIT_FAILURE);
}

void	*p_function(void *data)
{
	int				i;
	const int		max = 3;
	const char		*name = data;
	const pthread_t	tid = pthread_self();

	while (++i < max)
	{
		printf("<%s> tid : %x (%d/%d)\n",
			name, (unsigned int)tid, i, max);
		usleep(1000 * 1000);
	}
	return ((void *)12345);
}
