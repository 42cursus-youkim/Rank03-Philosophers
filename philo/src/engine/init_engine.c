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
	init_mutex(&philo->lock);
}

void	init_engine(t_engine *e, const int argc, const char *argv[])
{
	int	id;

	init_flag(e, argc, argv);
	init_mutex(&e->available);
	e->philos = ymalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	e->forks = ymalloc((e->flag[num_philos] + 1) * sizeof(pthread_mutex_t));
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		init_mutex(&e->forks[id]);
		init_philosopher(e, id, &e->philos[id]);
	}
}

void	run_engine(t_engine *e)
{
	int	id;

	id = 0;
	while (++id <= e->flag[num_philos])
		pthread_create(&e->philos[id].thread, NULL,
						p_function, &e->philos[id]);
	id = 0;
	while (++id <= e->flag[num_philos])
		pthread_join(e->philos[id].thread, NULL);
}