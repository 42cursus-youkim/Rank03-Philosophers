#include "philosophers.h"

/*	allocate memory for philosophers and forks. id starts from 1.
*/
void	init_engine(t_engine *e, int argc, char *argv[])
{
	check_argc(argc);
	init_flag(e, argc, argv);
	new_semtex(&e->enginelock, "engine", 1);
	new_semtex(&e->forks, "forks", e->flag[num_philos]);
	e->pids = ycalloc(e->flag[num_philos] * sizeof(int));
}

int	spawn_procs(t_engine *e)
{
	int	id;
	int	pid;

	id = -1;
	while (++id < e->flag[num_philos])
	{
		pid = fork();
		e->pids[id] = pid;
		if (pid == IS_CHILD)
			break ;
		else if (pid < 0)
			yerror("error while forking");
	}
	return (pid);
}

void	del_engine(t_engine *e)
{
	del_semtex(&e->enginelock);
	del_semtex(&e->forks);
	free(e->pids);
}
