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
	philo->last_eat = e->start_time;
	init_mutex(&philo->lock);
}

/*	allocate memory for philosophers and forks. id starts from 1.
*/
void	init_engine(t_engine *e, const int argc, const char *argv[])
{
	int	id;

	init_flag(e, argc, argv);
	init_mutex(&e->enginelock);
	pthread_mutex_lock(&e->enginelock);
	pthread_mutex_unlock(&e->enginelock);
	return ;
	e->philos = ycalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	e->forks = ycalloc((e->flag[num_philos] + 1) * sizeof(pthread_mutex_t));
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		init_mutex(&e->forks[id]);
		init_philosopher(e, id, &e->philos[id]);
	}
}
