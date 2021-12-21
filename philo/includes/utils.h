#ifndef UTILS_H
# define UTILS_H

typedef enum e_flag
{
	OK = 0,
	ERR = -1,
}	t_flag;

typedef enum e_in_usec
{
	mili_in_usec = 1000,
	sec_in_mili = 1000,
	sec_in_usec = 1000 * mili_in_usec,
}	t_in_usec;

typedef void *(*routine)(void *arg);

//	@func
/*
** < util_thread.c > */

int		new_thread(pthread_t *pthread, routine func, void *arg);
/*
** < util_time.c > */

size_t	getmsec(void);
size_t	timediff(size_t start);
void	msleep(size_t ms);
//	@end
#endif