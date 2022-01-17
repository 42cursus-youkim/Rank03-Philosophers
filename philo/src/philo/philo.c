#include "philosophers.h"


static void	pickup_fork(t_philo *philo)
{
	// const pthread_mutex_t	order[2][2] = {
	// 	{philo->left, philo->right},
	// 	{philo->right, philo->left}
	// };

	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right);
	}
	else
	{
		pthread_mutex_lock(philo->left);
	}
	atomic_print_msg(philo, TAKEFORK);
	// if (philo->e->flag[num_philos] == 1)
	// {
	// 	// pthread_mutex_unlock(philo->right);
	// 	return ((void)msleep(philo->e->flag[time_to_die]));
	// }
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left);
	}
	else
	{
		pthread_mutex_lock(philo->right);
	}
	atomic_print_msg(philo, TAKEFORK);
}

static void	eat(t_philo *philo)
{
	gettimeofday(&philo->last_eat, NULL);
	philo->eats++;
	atomic_finish_eating(philo);
	atomic_print_msg(philo, EATING);
	msleep(philo->e->flag[time_to_eat]);
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
	else
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
	}
}

//https://cs.colby.edu/courses/F19/cs333/notes/9.ConcurrentProgramming(2).pdf
static void	sleeps(t_philo *philo)
{
	atomic_print_msg(philo, SLEEPING);
	msleep(philo->e->flag[time_to_sleep]);
}

static void	think(t_philo *philo)
{
	atomic_print_msg(philo, THINKING);
}


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2)
		msleep(philo->e->flag[time_to_eat]);

	while (philo->e->is_running)
	{
		pickup_fork(philo);
		eat(philo);
		sleeps(philo);
		think(philo);
	}
	return (NULL);
}
