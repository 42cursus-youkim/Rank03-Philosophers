#ifndef PHILO_H
# define PHILO_H

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
** < philo.c > */

void	*routine(void *arg);
/*
** < manager.c > */

void	*eat_manager(void *arg);
void	*death_manager(void *arg);
#endif