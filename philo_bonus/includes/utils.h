#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < ylogging.c > */

void	print_msg(t_philo *philo, t_state state);
void	atomic_print_msg(t_philo *philo, t_state state);
/*
** < ysemtex.c > */

void	semtex_init(t_semtex *semtex, const char *name, int amount);
void	semtex_destroy(t_semtex *semtex);
void	semtex_lock(t_semtex *semtex);
void	semtex_unlock(t_semtex *semtex);
/*
** < ythread.c > */

void	init_thread(pthread_t *pthread, t_routine_f func, void *arg);
void	init_mutex(pthread_mutex_t *mutex);
/*
** < ytime.c > */

size_t	getusec(void);
void	msleep(size_t ms);
size_t	msec_diff(struct timeval from);
/*
** < yutils-old.c > */

void	yatoui(const char *str, int *n);
int		exit_err(t_err err);
void	atomic_stop_running(t_engine *e);
//	@end
#endif