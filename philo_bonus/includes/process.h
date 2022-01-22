#ifndef PROCESS_H
# define PROCESS_H

typedef struct s_engine
{
	int				flag[6];
	t_ysem			forks;
	// int				*pids;
	struct s_philo	*philos;
	t_ysem			enginelock;
	struct timeval	start_time;
	bool			is_running;
}	t_engine;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	int				eats;
	pthread_t		manager;
	struct s_engine	*e;
	struct timeval	last_eat;
}	t_philo;

//	@func
/*
** < engine_proc.c > */

void	engine_proc(t_engine *e);
/*
** < philo_proc.c > */

void	philo_proc(t_philo *philo);
#endif