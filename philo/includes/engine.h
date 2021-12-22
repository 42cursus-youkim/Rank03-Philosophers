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
	int				eats;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*available;
	struct timeval	last_eat;
	struct s_engine	*e;
}	t_philo;

typedef struct s_engine
{
	int				flag[5];
	pthread_mutex_t	*forks;
	t_philo			*philos;
	struct timeval	start_time;
	pthread_mutex_t	*engine_available;
}	t_engine;

//	@func
/*
** < init_engine.c > */

void	init_flag(t_engine *e, const int argc, const char *argv[]);
void	init_engine(t_engine *e);
void	del_engine(t_engine *e);
/*
** < philo.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
//	@end
#endif