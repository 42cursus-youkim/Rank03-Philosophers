#include "philosophers.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->left);
	print_msg(philo, "has taken a fork");
}

static void	eat(t_philo *philo)
{
	philo->eats++;
	print_msg(philo, "is eating");
	msleep(philo->e->flag[time_to_eat]);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (philo->eats == philo->e->flag[nums_need_eat])
		philo->e->flag[nums_philos_finished_eat]++;
	// FIXME: convert to mutex and send to manager
	if (philo->e->flag[nums_philos_finished_eat] == philo->e->flag[num_philos])
		philo->e->is_running = false;
}

static void	sleeps(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	msleep(philo->e->flag[time_to_sleep]);
}

static void	think(t_philo *philo)
{
	print_msg(philo, "is thinking");
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
