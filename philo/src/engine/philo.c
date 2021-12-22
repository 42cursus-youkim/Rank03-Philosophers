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
	pthread_mutex_init(&e->forks[id], NULL);
}