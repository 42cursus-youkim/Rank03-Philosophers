#include "philosophers.h"

bool	is_everyone_finished_eat(t_engine *e)
{
	return (e->flag[nums_philos_finished_eat] == e->flag[num_philos]);
}

/*	increase the number of philosophers who finished eating.
	variable race condition protected with mutex[e->lock].
*/
void	add_finished_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->e->enginelock);
	if (philo->eats == philo->e->flag[nums_need_eat])
		philo->e->flag[nums_philos_finished_eat]++;
	pthread_mutex_unlock(&philo->e->enginelock);
}

void	del_engine(t_engine *e)
{
	int	id;

	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_join(e->philos[id].thread, NULL);
	}
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_mutex_destroy(&e->forks[id]);
		pthread_mutex_destroy(&e->philos[id].lock);
	}
	free(e->forks);
	free(e->philos);
	pthread_mutex_destroy(&e->enginelock);
}
