#include "philosophers.h"

void	run_engine(t_engine *e)
{
	int			id;
	pthread_t	temp;

	id = 0;
	while (++id <= e->flag[num_philos])
	{
		init_thread(&e->philos[id].thread, routine, &e->philos[id]);
	}
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		init_thread_detached(&temp, death_manager, &e->philos[id]);
		// if (e->flag[nums_need_eat] > 0)
		//  	init_thread_detached(&temp, eat_manager, &e->philos[id]);
	}
	printf("engine's mutex address: %p\n", &e->enginelock);
}

//	atomically update value to prevent race condition.
void	engine_atomic_update(t_philo *philo, int *val, int amount)
{
	pthread_mutex_lock(&philo->e->enginelock);
	*val += amount;
	pthread_mutex_unlock(&philo->e->enginelock);
}
