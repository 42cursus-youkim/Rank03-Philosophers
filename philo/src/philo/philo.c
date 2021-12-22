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
	print_msg(philo, "is eating");
	msleep(philo->e->flag[time_to_eat]);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (++philo->eats == philo->e->flag[nums_need_eat])
		philo->e->flag[nums_philos_finished_eat]++;
}

static void	go_sleep(t_philo *philo)
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
	while (true)
	{
		pickup_fork(philo);
		eat(philo);
		go_sleep(philo);
		think(philo);
	}
	return (NULL);
}
