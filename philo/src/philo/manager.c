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
	// bool	is_running;

	philo = arg;
	if (philo)
		philo->e->is_running = false;
	// atomic_is_running(philo->e, &is_running);
	// // printf("manager's mutex address: %p\n", &philo->e->lock);
	// while (is_running)
	// {
	// 	pthread_mutex_lock(&philo->e->enginelock);
	// // 	if (msec_diff(philo->last_eat) >= (size_t)philo->e->flag[time_to_die])
	// // 	{
	// // 		print_msg(philo, DIED);
	// 		usleep(1000 * 20);
	// 		philo->e->is_running = false;
	// // 	}
	// 	pthread_mutex_unlock(&philo->e->enginelock);
	// // 	msleep(10);
	// }
	return (NULL);
}
