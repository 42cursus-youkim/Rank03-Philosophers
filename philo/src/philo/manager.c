#include "philosophers.h"

static void	check_philos(t_engine *e, t_philo *philos)
{
	int			id;

	id = 0;
	while (++id <= e->flag[num_philos])
	{
		// printf("[manager] reading info from thread %d\n", philos[id].id);
		pthread_mutex_lock(&e->enginelock);
		if (msec_diff(philos[id].last_eat) >= (size_t)e->flag[time_to_die])
		{
			print_msg(&philos[id], DIED);
			e->is_running = false;
		}
		if (e->flag[nums_need_eat]
			&& e->flag[nums_philos_finished_eat] == e->flag[num_philos])
			e->is_running = false;
		pthread_mutex_unlock(&e->enginelock);
	}
}

//	gets pointer to engine as input.
void	*manager(void *arg)
{

	t_engine	*e;
	t_philo		*philos;

	e = arg;
	philos = e->philos;

	while (e->is_running)
	{
		check_philos(e, philos);
		msleep(2);
	}
	return (NULL);
}
