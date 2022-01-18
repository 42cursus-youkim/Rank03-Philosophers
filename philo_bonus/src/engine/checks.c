#include "philosophers.h"

t_err	check_argc(int argc)
{
	if (5 <= argc && argc <= 6)
		return (OK);
	printf("Usage: %s%s\n",
		"./philosophers num_philos time_to_die",
		"time_to_eat time_to_sleep [nums_need_eat]");
	exit(1);
}

void	init_flag(t_engine *e, int argc, char *argv[])
{
	int		i;

	check_argc(argc);
	e->is_running = true;
	e->flag[nums_need_eat] = 0;
	e->flag[nums_philos_finished_eat] = 0;
	i = -1;
	while (++i < argc - 1)
		if (yatoui(argv[i + 1], &e->flag[i]) != OK)
			yerror("cannot convert given argument to non-negative integer");
	if (e->flag[num_philos] <= 0)
		yerror("number of philosophers must be positive");
	gettimeofday(&e->start_time, NULL);
}
