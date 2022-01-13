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

//	gets pointer to engine as input.
void	*death_manager(void *arg)
{
	// int			id;
	t_engine	*e;
	t_philo		*philos;

	e = arg;
	philos = e->philos;
	if (!philos)
		return (NULL);
	printf("[manager] hi\n");
	// id = 0;
	// while (++id <= e->flag[num_philos])
	// {
	// 	printf("[manager] reading info from thread %d\n", philos[id].id);
	// }
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
