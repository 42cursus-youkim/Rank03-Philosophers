#include "philosophers.h"

t_err	yatoui(const char *str, int *n)
{
	int	i;

	i = 0;
	*n = 0;
	if (!str || str[0] == '-')
		return (ERR_ARG);
	while ('0' <= str[i] && str[i] <= '9')
		(*n) = (*n) * 10 + (str[i++] - '0');
	return (OK);
}

//	uses internal memset
void	*ycalloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (memset(ptr, 0, size));
}

int	exit_err(t_err err)
{
	const char	*err_msg[] = {
		"NOT AN ERROR",
		"Usage: ./philosophers\
		num_philos time_to_die time_to_eat time_to_sleep [nums_need_eat]",
		"cannot convert given argument to non-negative integer",
		"failed to allocate memory",
		"number of philosophers must be positive",
	};

	printf("%s\n", err_msg[err]);
	return (1);
}

bool	atomic_is_running(t_engine *e)
{
	bool	ret;

	pthread_mutex_lock(&e->enginelock);
	ret = e->is_running;
	pthread_mutex_unlock(&e->enginelock);
	return (ret);
}