#ifndef UTILS_H
# define UTILS_H

# define END "\e[0m"
# define BHRED "\e[1;91m"

typedef enum e_res
{
	OK = 0,
	ERR = -1,
}	t_res;

typedef enum e_in_usec
{
	mili_in_usec = 1000,
	sec_in_mili = 1000,
	sec_in_usec = 1000 * mili_in_usec,
}	t_in_usec;

typedef void *(*t_routine_f)(void *arg);

//	@func
/*
** < ythread.c > */

t_res	new_thread(pthread_t *pthread, t_routine_f func, void *arg);
t_res	new_mutex(pthread_mutex_t *mutex);
void	*p_function(void *data);
/*
** < ytime.c > */

size_t	getmsec(void);
size_t	timediff(size_t start);
void	msleep(size_t ms);
/*
** < yutils.c > */

void	yerror(const char *msg);
void	yassert(const bool cond, const char *msg);
t_res	yatoui(const char *str, int *n);
//	@end
#endif