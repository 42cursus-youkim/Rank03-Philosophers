#include "philosophers.h"

static bool	is_dead(t_engine *e, t_philo *philos, int id)
{
	return (msec_diff(philos[id].last_eat) >= (size_t)e->flag[time_to_die]);
}

static bool	is_all_finished(t_engine *e)
{
	return (e->flag[nums_need_eat]
			&& e->flag[nums_philos_finished_eat] == e->flag[num_philos]);
}

static void	check_philos(t_engine *e, t_philo *philos)
{
	int			id;

	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_mutex_lock(&e->enginelock);
		if (is_dead(e, philos, id))
		{
			print_msg(&philos[id], DIED);
			e->is_running = false;
			// printf("[manager] thread %d died\n", philos[id].id);
		}
		if (is_all_finished(e))
		{
			e->is_running = false;
			// printf("[manager] everyone finished eating\n");
		}
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
