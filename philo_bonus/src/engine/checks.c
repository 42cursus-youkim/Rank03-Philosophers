#include "philosophers.h"

void	check_argc(int argc)
{
	if (5 <= argc && argc <= 6)
		return;
	printf("Usage: %s %s",
		"./philosophers num_philos time_to_die",
		"time_to_eat time_to_sleep [nums_need_eat]");
	exit(1);
}

void	init_flag(t_engine *e, int argc, char *argv[])
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
			yerror("invalid argument");
	if (e->flag[num_philos] <= 0)
		return (ERR_PHILO);
	gettimeofday(&e->start_time, NULL);
	return (OK);
}
