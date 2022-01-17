#include "philosophers.h"

void	init_philosopher(t_engine *e, int id, t_philo *philo)
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	philo->e = e;
	philo->id = id;
	left = &e->forks[id];
	if (id == e->flag[num_philos])
		right = &e->forks[1];
	else
		right = &e->forks[id + 1];
	if (id % 2)
	{
		philo->pick_first = left;
		philo->pick_last = right;
	}
	else
	{
		philo->pick_first = right;
		philo->pick_last = left;
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
	pthread_mutex_init(&e->enginelock, NULL);
	e->philos = ycalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	if (!e->philos)
		return (ERR_MEM);
	e->forks = ycalloc((e->flag[num_philos] + 1) * sizeof(pthread_mutex_t));
	if (!e->forks)
		return (ERR_MEM);
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_mutex_init(&e->forks[id], NULL);
		init_philosopher(e, id, &e->philos[id]);
	}
	return (OK);
}
