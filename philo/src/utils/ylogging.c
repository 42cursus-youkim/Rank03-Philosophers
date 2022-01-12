#include "philosophers.h"

static const char	*philocolor(t_philo *philo)
{
	const char	*color[] = {
		"", BGRN, BBLU, BYEL, BMAG, BCYN, BRED, BWHT
	};

	if (philo->e->flag[num_philos] > 7)
		return (color[0]);
	return (color[philo->id]);
}

void	print_msg(t_philo *philo, t_state state)
{
	const char	*msgcolor[5] = {HCYN, GRN, HMAG, YEL, REDB};
	const char	*msg[5] = {
		"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"
	};

	pthread_mutex_lock(&philo->e->lock);
	if (philo->e->is_running)
		printf("%s%-6zu %-3d %s%s%s\n",
			philocolor(philo), msec_diff(philo->e->start_time), philo->id,
			msgcolor[state], msg[state], END);
	pthread_mutex_unlock(&philo->e->lock);
}