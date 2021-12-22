#include "philo.h"

size_t	getmsec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * sec_in_mili) + (tv.tv_usec / mili_in_usec));
}

//	diff in time in miliseconds
size_t	timediff(size_t start)
{
	const size_t	now = getmsec();

	printf("now: %zu, start: %zu\n", now, start);
	return (now - start);
}

/*	sleep in miliseconds
	TODO: sync with loop
*/
void	msleep(size_t ms)
{
	usleep(ms * mili_in_usec);
}