#include "philosophers.h"

t_err	check_argc(int argc)
{
	if (5 <= argc && argc <= 6)
		return (OK);
	return (ERR_ARG);
}

t_err	init_flag(t_engine *e, int argc, char *argv[])
{
	int		i;
	t_err	err;

	err = check_argc(argc);
	if (err)
		return (err);
	e->is_running = true;
	e->flag[nums_need_eat] = 0;
	e->flag[nums_philos_finished_eat] = 0;
	i = -1;
	while (++i < argc - 1)
		if (yatoui(argv[i + 1], &e->flag[i]) != OK)
			return (ERR_NUM);
	if (e->flag[num_philos] <= 0)
		return (ERR_PHILO);
	gettimeofday(&e->start_time, NULL);
	return (OK);
}
