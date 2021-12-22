#ifndef ENGINE_H
# define ENGINE_H

typedef enum e_flag
{
	num_philos = 0,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	nums_need_eat,
}	t_flag;

typedef struct s_philo
{
	int				id;
	// int				to_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

typedef struct s_engine
{
	int				flag[5];
	pthread_mutex_t	*forks;
	t_philo			*philosophers;
}	t_engine;

//	@func
/*
** < philosophers.c > */

void	check_argc(const int argc);
void	init_engine(t_engine *e, const int argc, const char *argv[]);
//	@end
#endif