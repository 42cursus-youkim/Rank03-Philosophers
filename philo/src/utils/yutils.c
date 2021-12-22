#include "philosophers.h"

void	print_msg(t_philo *philo, char *str)
{
	const size_t	ms = msec_diff(philo->e);

	pthread_mutex_lock(&philo->e->available);
	printf("%zu\t%d\t%s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->e->available);
}

void	yerror(const char *msg, const char *value)
{
	printf("%s[Error]\n\t%s: %s%s\n", BHRED, msg, value, END);
	exit(EXIT_FAILURE);
}

void	yassert(const bool cond, const char *msg)
{
	if (!cond)
		yerror(msg, "");
}

t_res	yatoui(const char *str, int *n)
{
	int	i;

	i = 0;
	*n = 0;
	if (!str || str[0] == '-')
		return (ERR);
	while ('0' <= str[i] && str[i] <= '9')
		(*n) = (*n) * 10 + (str[i++] - '0');
	return (OK);
}

//	no NULL-termination, use new_ystr* for that
void	*ymalloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	yassert(ptr, "malloc failed");
	return (ptr);
}
