#include "philosophers.h"

void	*manager(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->e->is_running)
	{
		if (msec_diff(philo->last_eat) >= (size_t)philo->e->flag[time_to_die])
		{
			philo->e->is_running = false;
			print_msg(philo, DIED);
		}
	}
	return (NULL);
}
