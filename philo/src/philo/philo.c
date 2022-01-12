#include "philosophers.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_msg(philo, TAKEFORK);
	pthread_mutex_lock(philo->left);
	print_msg(philo, TAKEFORK);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	philo->eats++;
	print_msg(philo, EATING);
	gettimeofday(&philo->last_eat, NULL);
	msleep(philo->e->flag[time_to_eat]);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (philo->eats == philo->e->flag[nums_need_eat])
		philo->e->flag[nums_philos_finished_eat]++;
	if (is_everyone_finished_eat(philo->e))
		philo->e->is_running = false;
	pthread_mutex_unlock(&philo->lock);
}
// FIXME: convert to mutex and send to manager

static void	sleeps(t_philo *philo)
{
	print_msg(philo, SLEEPING);
	msleep(philo->e->flag[time_to_sleep]);
}

static void	think(t_philo *philo)
{
	print_msg(philo, THINKING);
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
