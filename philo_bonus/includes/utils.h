#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < ytime.c > */

size_t	getusec(void);
void	msleep(size_t ms);
size_t	msec_diff(struct timeval from);
/*
** < ythread.c > */

void	init_thread(pthread_t *pthread, t_routine_f func, void *arg);
void	init_mutex(pthread_mutex_t *mutex);
/*
** < yutils.c > */

t_err	yatoui(const char *str, int *n);
void	*ycalloc(const size_t size);
int		exit_err(t_err err);
void	atomic_stop_running(t_engine *e);
/*
** < ylogging.c > */

void	print_msg(t_philo *philo, t_state state);
void	atomic_print_msg(t_philo *philo, t_state state);
//	@end
#endif