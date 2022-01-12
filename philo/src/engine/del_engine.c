#include "philosophers.h"

bool	is_everyone_finished_eat(t_engine *e)
{
	return (e->flag[nums_philos_finished_eat] == e->flag[num_philos]);
}

void	del_engine(t_engine *e)
{
	int	id;

	pthread_mutex_destroy(&e->lock);
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_join(e->philos[id].thread, NULL);
		pthread_mutex_destroy(&e->forks[id]);
		pthread_mutex_destroy(&e->philos[id].lock);
	}
	free(e->forks);
	free(e->philos);
}
