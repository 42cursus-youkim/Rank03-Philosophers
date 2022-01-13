#ifndef ENGINE_H
# define ENGINE_H


#include "philo.h"
#include <bits/pthreadtypes.h>
#include <bits/types/struct_timeval.h>
#include <stdbool.h>

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
void	engine_atomic_update(t_philo *philo, int *val, int amount);
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
void	init_engine(t_engine *e, const int argc, const char *argv[]);
/*
** < checks.c > */

void	check_argc(const int argc);
void	init_flag(t_engine *e, const int argc, const char *argv[]);
/*
** < del_engine.c > */

bool	is_everyone_finished_eat(t_engine *e);
void	add_finished_eat(t_philo *philo);
void	del_engine(t_engine *e);
//	@end
#endif