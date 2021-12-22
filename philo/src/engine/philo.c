#include "philosophers.h"

void	print_msg(t_philo *philo, char *str)
{
	const size_t	ms = msec_diff(philo->e);

	pthread_mutex_lock(&philo->e->available);
	printf("%zu\t%d\t%s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->e->available);
}

size_t	msec_diff(t_engine *e)
{
	struct timeval	now;
	size_t			diff;

	gettimeofday(&now, NULL);
	diff = (now.tv_sec - e->start_time.tv_sec) * sec_in_mili;
	diff += (now.tv_usec - e->start_time.tv_usec) / mili_in_usec;
	return (diff);
}