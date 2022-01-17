#include "philosophers.h"

void	init_philosopher(t_engine *e, int id, t_philo *philo)
{
	philo->e = e;
	philo->id = id;
	philo->left = &e->forks[id];
	if (id == e->flag[num_philos])
		philo->right = &e->forks[1];
	else
		philo->right = &e->forks[id + 1];
	if (id % 2)
	{
		philo->pick_first = philo->left;
		philo->pick_last = philo->right;
	}
	else
	{
		philo->pick_first = philo->right;
		philo->pick_last = philo->left;
	}
	philo->last_eat = e->start_time;
}

/*	allocate memory for philosophers and forks. id starts from 1.
*/
t_err	init_engine(t_engine *e, int argc, char *argv[])
{
	int		id;
	t_err	err;

	err = init_flag(e, argc, argv);
	if (err)
		return (err);
	init_mutex(&e->enginelock);
	e->philos = ycalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	if (!e->philos)
		return (ERR_MEM);
	e->forks = ycalloc((e->flag[num_philos] + 1) * sizeof(pthread_mutex_t));
	if (!e->forks)
		return (ERR_MEM);
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		init_mutex(&e->forks[id]);
		init_philosopher(e, id, &e->philos[id]);
	}
	return (OK);
}
