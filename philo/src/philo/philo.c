#include "philosophers.h"


static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->pick_first);
	atomic_print_msg(philo, TAKEFORK);
	pthread_mutex_lock(philo->pick_last);
	atomic_print_msg(philo, TAKEFORK);
}

static void	eat(t_philo *philo)
{
	gettimeofday(&philo->last_eat, NULL);
	philo->eats++;
	atomic_finish_eating(philo);
	atomic_print_msg(philo, EATING);
	msleep(philo->e->flag[time_to_eat]);
	pthread_mutex_unlock(philo->pick_last);
	pthread_mutex_unlock(philo->pick_first);
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
		msleep(philo->e->flag[time_to_eat] / 2);
	while (atomic_is_running(philo->e))
	{
		pickup_fork(philo);
		eat(philo);
		sleeps(philo);
		think(philo);
	}
	return (NULL);
}
