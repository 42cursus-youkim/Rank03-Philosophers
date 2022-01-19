#ifndef PROCESS_H
# define PROCESS_H

typedef struct s_philo
{
	int				pid;
	int				eats;
	// pthread_t		thread;
	// struct s_engine	*e;
	struct timeval	last_eat;
}	t_philo;

//	@func
/*
** < procs.c > */

void	philo_proc(void);
void	engine_proc(t_engine *e);
#endif