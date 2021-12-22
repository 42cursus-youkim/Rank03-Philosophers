#ifndef UTILS_H
# define UTILS_H

# define END "\e[0m"
# define BHRED "\e[1;91m"

typedef enum e_flag
{
	num_philos = 0,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	nums_need_eat,
	nums_philos_finished_eat,
}	t_flag;

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

//	@func
/*
** < ymutex.c > */

void	init_mutex(pthread_mutex_t *mutex);
/*
** < ythread.c > */

t_res	init_thread(pthread_t *pthread, t_routine_f func, void *arg);
void	*p_function(void *data);
/*
** < ytime.c > */

size_t	getusec(void);
void	msleep(size_t ms);
size_t	msec_diff(t_engine *e);
/*
** < yutils.c > */

void	print_msg(t_philo *philo, char *str);
void	yerror(const char *msg, const char *value);
void	yassert(const bool cond, const char *msg);
t_res	yatoui(const char *str, int *n);
void	*ymalloc(const size_t size);
//	@end
#endif