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
