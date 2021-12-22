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
		usleep(1);
}
