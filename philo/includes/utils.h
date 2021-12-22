#ifndef UTILS_H
# define UTILS_H

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

typedef struct s_philo
{
	int				id;
	int				to_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

typedef struct s_info
{
	int		philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nums_to_eat;
	t_philo	*philosophers;
}	t_info;

typedef void *(*t_routine_f)(void *arg);

//	@func
/*
** < util_print.c > */

void	yerror(const char *msg);
/*
** < util_thread.c > */

t_res	new_thread(pthread_t *pthread, t_routine_f func, void *arg);
t_res	new_mutex(pthread_mutex_t *mutex);
void	*p_function(void *data);
/*
** < util_time.c > */

size_t	getmsec(void);
size_t	timediff(size_t start);
void	msleep(size_t ms);
//	@end
#endif