#include "philosophers.h"

void	run_engine(t_engine *e)
{
	int			id;
	// pthread_t	temp;

	id = 0;
	while (++id <= e->flag[num_philos])
	{
		init_thread(&e->philos[id].thread, routine, &e->philos[id]);
	}
	// return ;
	// TODO: init monitor funcs here again
}

void	del_engine(t_engine *e)
{
	int	id;
	pthread_t thread;

	id = 0;
	init_thread(&thread, death_manager, e);
	// if (e->flag[nums_need_eat] > 0)
	//  	init_thread_detached(&temp, eat_manager, &e->philos[id]);
	while (++id <= e->flag[num_philos])
	{
		pthread_join(e->philos[id].thread, NULL);
		pthread_mutex_destroy(&e->forks[id]);
		pthread_mutex_destroy(&e->philos[id].lock);
	}
	free(e->forks);
	free(e->philos);
	pthread_join(thread, NULL);
	pthread_mutex_destroy(&e->enginelock);
}