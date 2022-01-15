#include "philosophers.h"

size_t	getusec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * sec_in_usec + tv.tv_usec);
}

//	sleep in miliseconds
void	msleep(size_t ms)
{
	const size_t	start = getusec();

	while (getusec() - start <= ms * mili_in_usec)
		usleep(10);
}

size_t	msec_diff(struct timeval from)
{
	struct timeval	now;
	size_t			diff;

	gettimeofday(&now, NULL);
	diff = (now.tv_sec - from.tv_sec) * sec_in_mili;
	diff += (now.tv_usec - from.tv_usec) / mili_in_usec;
	return (diff);
}
