#include "philosophers.h"

t_res	init_thread(pthread_t *pthread, t_routine_f func, void *arg)
{
	const t_res	res = pthread_create(pthread, NULL, func, arg);

	if (res == OK)
		return (res);
	printf("Error: could not initialize thread\n");
	exit(EXIT_FAILURE);
}

void	init_mutex(pthread_mutex_t *mutex)
{
	int			i;
	const int	res = pthread_mutex_init(mutex, NULL);
	const int	errors[2] = {EINVAL, EDEADLK};
	const char	*err_msg[] = {"invalid value", "deadlock!"};

	i = -1;
	while (++i < 2)
		if (res == errors[i])
			yerror("mutex initialization failed", err_msg[i]);
}

void	*p_function(void *data)
{
	int				i;
	const int		max = 3;
	const char		*name = data;
	const pthread_t	tid = pthread_self();

	i = -1;
	while (++i < max)
	{
		printf("<%s> tid : %x (%d/%d)\n",
			name, (unsigned int)tid, i, max);
		usleep(1000 * 1000);
	}
	return ((void *)12345);
}
