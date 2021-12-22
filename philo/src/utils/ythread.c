#include "philosophers.h"

t_res	init_thread(pthread_t *pthread, t_routine_f func, void *arg)
{
	const t_res	res = pthread_create(pthread, NULL, func, arg);

	if (res == OK)
		return (res);
	printf("Error: could not initialize thread\n");
	exit(EXIT_FAILURE);
}

void	*p_function(void *data)
{
	int		i;
	t_philo	*philo;
	// const pthread_t	tid = pthread_self();

	philo = (t_philo *)data;
	i = -1;
	while (++i < 100)
	{
		print_msg(philo, "says hi");
		msleep(100);
	}
	if (data || !data)
		return ((void *)12345);
	return (NULL);
}
