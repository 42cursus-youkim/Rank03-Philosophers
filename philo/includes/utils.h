#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < ytime.c > */

size_t	getusec(void);
void	msleep(size_t ms);
size_t	msec_diff(struct timeval from);
/*
** < yutils.c > */

t_err	yatoui(const char *str, int *n);
void	*ycalloc(const size_t size);
int		exit_err(t_err err);
bool	atomic_is_running(t_engine *e);
void	atomic_finish_eating(t_philo *philo);
/*
** < ylogging.c > */

void	print_msg(t_philo *philo, t_state state);
void	atomic_print_msg(t_philo *philo, t_state state);
//	@end
#endif