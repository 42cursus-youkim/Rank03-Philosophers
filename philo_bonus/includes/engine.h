#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_engine
{
	int				flag[6];
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
	pthread_mutex_t	enginelock;
	struct timeval	start_time;
	bool			is_running;
}	t_engine;

typedef void *(*t_routine_f)(void *arg);
//	@func
/*
** < checks.c > */

t_err	check_argc(int argc);
void	init_flag(t_engine *e, int argc, char *argv[]);
/*
** < del_engine.c > */

bool	is_everyone_finished(t_engine *e);
void	atomic_finish_eating(t_philo *philo);
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
void	init_engine(t_engine *e, int argc, char *argv[]);
/*
** < run_engine.c > */

void	run_engine(t_engine *e);
void	del_engine(t_engine *e);
//	@end
#endif