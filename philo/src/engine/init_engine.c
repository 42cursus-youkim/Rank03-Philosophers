#include "philosophers.h"

void	init_engine(t_engine *e, const int argc, const char *argv[])
{
	int	id;

	init_flag(e, argc, argv);
	gettimeofday(&e->start_time, NULL);
	e->philos = ymalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	e->forks = ymalloc((e->flag[num_philos] + 1) * sizeof(pthread_mutex_t));
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_mutex_init(&e->forks[id], NULL);
		init_philosopher(e, id ,&e->philos[id]);
	}
}

void	del_engine(t_engine *e)
{
	int	id;

	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_mutex_destroy(&e->forks[id]);
	}
	free(e->forks);
	free(e->philos);
}