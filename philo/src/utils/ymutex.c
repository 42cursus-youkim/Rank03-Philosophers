#include "philosophers.h"

void	init_mutex(pthread_mutex_t *mutex)
{
	int			i;
	const int	res = pthread_mutex_init(mutex, NULL);
	const int	errors[2] = {EINVAL, EDEADLK};
	const char	*err_msg[] = {"invalid value", "deadlock!"};

	i = -1;
	while (++i < 2)
		if (res == errors[i])
			yerror("mutex initialization failed", err_msg[i]);
}
