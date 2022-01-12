#ifndef PHILO_H
# define PHILO_H

typedef enum s_state
{
	TAKEFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_state;

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
/*
** < manager.c > */

void	*eat_manager(void *arg);
void	*death_manager(void *arg);
#endif