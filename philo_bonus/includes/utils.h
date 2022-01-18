#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < yasync.c > */

void	semtex_init(t_semtex *semtex, const char *name, int amount);
void	semtex_destroy(t_semtex *semtex);
void	semtex_lock(t_semtex *semtex);
void	semtex_unlock(t_semtex *semtex);
/*
** < ylogging.c > */

void	print_msg(t_philo *philo, t_state state);
/*
** < ystr.c > */

char	*new_ystr(const char *from);
char	*new_ystrm(int length);
int		ystrlen(const char *str);
int		ystrcpy(char *dst, const char *src);
int		ystr_append(char **pstr, char *src);
/*
** < ytime.c > */

size_t	getusec(void);
void	msleep(size_t ms);
size_t	msec_diff(struct timeval from);
/*
** < yutils.c > */

t_err	yatoui(const char *str, int *n);
char	*yuitoa(int n);
void	yerror(char *msg);
void	*ycalloc(const size_t size);
void	init_thread(pthread_t *pthread, t_routine_f func, void *arg);
//	@end
#endif