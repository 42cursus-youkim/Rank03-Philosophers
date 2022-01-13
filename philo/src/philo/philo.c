// #include "philo.h"
#include "philosophers.h"
#include <stdbool.h>

// static void	pickup_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->right);
// 	print_msg(philo, TAKEFORK);
// 	pthread_mutex_lock(philo->left);
// 	print_msg(philo, TAKEFORK);
// }

// static void	eat(t_philo *philo)
// {
// 	// pthread_mutex_lock(&philo->lock);
// 	gettimeofday(&philo->last_eat, NULL);
// 	philo->eats++;
// 	add_finished_eat(philo);
// 	print_msg(philo, EATING);
// 	msleep(philo->e->flag[time_to_eat]);
// 	pthread_mutex_unlock(philo->left);
// 	pthread_mutex_unlock(philo->right);
// 	// pthread_mutex_unlock(&philo->lock);
// }

// static void	sleeps(t_philo *philo)
// {
// 	print_msg(philo, SLEEPING);
// 	msleep(philo->e->flag[time_to_sleep]);
// }

// static void	think(t_philo *philo)
// {
// 	print_msg(philo, THINKING);
// }

void	*dummy_routine(void *arg)
{
	printf("I am called\n");
	return arg;
}

void	*routine(void *arg)
{
	t_philo	*philo;
	// bool	is_running;

	philo = arg;
	if (!philo)
		return (NULL);
	print_msg(philo, THINKING);
	// printf("philos's mutex address: %p\n", &philo->e->lock);
	// if (philo->id % 2)
	// 	msleep(philo->e->flag[time_to_eat]);
	// is_running = atomic_read(philo->e, &philo->e->is_running);
	// printf("is_running: %d\n", is_running);
	// while (true)
	// {

		// atomic_is_running(philo->e, &is_running);
		// pickup_fork(philo);
		// eat(philo);
		// sleeps(philo);
		// think(philo);
	// }
	return (NULL);
}
