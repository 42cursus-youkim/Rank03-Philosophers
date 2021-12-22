#ifndef PHILO_H
# define PHILO_H

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

//	@func
/*
** < philo.c > */

void	*routine(void *arg);
#endif