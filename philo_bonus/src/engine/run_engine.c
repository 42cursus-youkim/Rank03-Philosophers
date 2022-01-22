#include "philosophers.h"

void	init_philo(t_engine *e, t_philo *philo, int id)
{
	philo->e = e;
	philo->id = id;
	philo->eats = 0;
	philo->last_eat = e->start_time;
}

/*	allocate memory for philosophers and forks. id starts from 1.
*/
void	init_engine(t_engine *e, int argc, char *argv[])
{
	check_argc(argc);
	init_flag(e, argc, argv);
	new_semtex(&e->enginelock, "engine", 1);
	new_semtex(&e->forks, "forks", e->flag[num_philos]);
	// e->pids = ycalloc(e->flag[num_philos] * sizeof(int));
	e->philos = ycalloc(e->flag[num_philos] * sizeof(t_philo));
}

void	run_engine(t_engine *e)
{
	int		id;
	pid_t	pid;

	id = -1;
	while (++id < e->flag[num_philos])
	{
		pid = fork();
		init_philo(e, &e->philos[id], id);
		if (pid == IS_CHILD)
			return (philo_proc(&e->philos[id]));
		else if (pid < 0)
			yerror("error while forking");
	}
	engine_proc(e);
}

void	del_engine(t_engine *e)
{
	del_semtex(&e->enginelock);
	del_semtex(&e->forks);
	free(e->philos);
}
