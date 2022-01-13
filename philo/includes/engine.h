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
** < run_engine.c > */

void	run_engine(t_engine *e);
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
t_err	init_engine(t_engine *e, int argc, char *argv[]);
/*
** < checks.c > */

t_err	check_argc(int argc);
t_err	init_flag(t_engine *e, int argc, char *argv[]);
/*
** < del_engine.c > */

bool	is_everyone_finished_eat(t_engine *e);
void	atomic_finish_eating(t_philo *philo);
void	del_engine(t_engine *e);
//	@end
#endif