#include "philosophers.h"

void	*eat_manager(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->e->is_running)
	{
		pthread_mutex_lock(&philo->e->enginelock);
		if (is_everyone_finished_eat(philo->e))
			philo->e->is_running = false;
		pthread_mutex_unlock(&philo->e->enginelock);
		msleep(10);
	}
	return (NULL);
}

void	*death_manager(void *arg)
{
	t_philo	*philo;

	philo = arg;
	// printf("manager's mutex address: %p\n", &philo->e->lock);
	// while (philo->e->is_running)
	// {
	// 	pthread_mutex_lock(&philo->e->lock);
	// 	if (msec_diff(philo->last_eat) >= (size_t)philo->e->flag[time_to_die])
	// 	{
	// 		print_msg(philo, DIED);
	// 		philo->e->is_running = false;
	// 	}
	// 	pthread_mutex_unlock(&philo->e->lock);
	// 	msleep(10);
	// }
	usleep(1000 * 20);
	philo->e->is_running = false;
	// write(1, "I am called\n", 11);
	return (NULL);
}
