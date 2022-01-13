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

void	atomic_write(t_engine *e, int *which, int val)
{
	pthread_mutex_lock(&e->enginelock);
	*which = val;
	pthread_mutex_unlock(&e->enginelock);
}

void	*atomic_read(t_engine *e, void *which)
{
	void	*res;

	pthread_mutex_lock(&e->enginelock);
	res = which;
	pthread_mutex_unlock(&e->enginelock);
	return (res);
}