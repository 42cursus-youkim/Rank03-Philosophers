#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_philo
{
	int				id;
	int				eats;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	lock;
	struct s_engine	*e;
	struct timeval	last_eat;
}	t_philo;

typedef struct s_engine
{
	int				flag[5];
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	available;
	struct timeval	start_time;
	bool			is_running;
}	t_engine;

typedef void *(*t_routine_f)(void *arg);
//	@func
/*
** < checks.c > */

void	check_argc(const int argc);
void	init_flag(t_engine *e, const int argc, const char *argv[]);
/*
** < del_engine.c > */

void	del_engine(t_engine *e);
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
void	init_engine(t_engine *e, const int argc, const char *argv[]);
void	run_engine(t_engine *e);
/*
** < philo.c > */

void	*routine(void *arg);
//	@end
#endif