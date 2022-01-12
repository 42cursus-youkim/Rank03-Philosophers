#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_engine
{
	int				flag[6];
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
	pthread_mutex_t	lock_print;
	struct timeval	start_time;
	bool			is_running;
}	t_engine;

typedef void *(*t_routine_f)(void *arg);
//	@func
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
void	init_engine(t_engine *e, const int argc, const char *argv[]);
void	run_engine(t_engine *e);
/*
** < checks.c > */

void	check_argc(const int argc);
void	init_flag(t_engine *e, const int argc, const char *argv[]);
/*
** < del_engine.c > */

bool	is_everyone_finished_eat(t_engine *e);
void	del_engine(t_engine *e);
//	@end
#endif