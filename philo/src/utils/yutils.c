#include "philosophers.h"

void	print_msg(t_philo *philo, t_state state)
{
	const char *msg[5] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "is dead"
	};

	pthread_mutex_lock(&philo->e->lock);
	printf("%zu\t%d\t%s\n", msec_diff(philo->e), philo->id, msg[state]);
	pthread_mutex_unlock(&philo->e->lock);
}

void	yerror(const char *msg)
{
	printf("%s[Error]\n\t%s%s\n", BHRED, msg, END);
	exit(EXIT_FAILURE);
}

void	yassert(const bool cond, const char *msg)
{
	if (!cond)
		yerror(msg);
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
