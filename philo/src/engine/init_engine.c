#include "philosophers.h"

static void	check_argc(const int argc)
{
	if (5 <= argc && argc <= 6)
		return ;
	printf("Usage: ./philosophers %s",
		"num_philos time_to_die time_to_eat time_to_sleep [nums_need_eat]\n");
	exit(0);
}

void	init_flag(t_engine *e, const int argc, const char *argv[])
{
	int	i;

	check_argc(argc);
	e->flag[nums_need_eat] = 0;
	i = -1;
	while (++i < argc - 1)
		yassert(yatoui(argv[i + 1], &e->flag[i]) == OK,
			"cannot convert argument to non-negative integer");
	yassert(e->flag[num_philos] > 0, "number of philosophers must be positive");
}

void	init_engine(t_engine *e)
{
	int	id;

	gettimeofday(&e->start_time, NULL);
	e->philos = ymalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	e->forks = ymalloc((e->flag[num_philos] + 1) * sizeof(pthread_mutex_t));
	id = 0;
	while (++id <= e->flag[num_philos])
	{
		pthread_mutex_init(&e->forks[id], NULL);
		init_philosopher(e, id ,&e->philos[id]);
	}
}

void	del_engine(t_engine *e)
{
	int	id;

	id = 0;
	while (++id <= e->flag[num_philos])
		pthread_mutex_destroy(&e->forks[id]);
	free(e->forks);
	free(e->philos);
}