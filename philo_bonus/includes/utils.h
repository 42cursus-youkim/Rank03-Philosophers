#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < ysemtex.c > */

void	new_semtex(t_semtex *semtex, char *name, int amount);
void	del_semtex(t_semtex *semtex);
void	semtex_lock(t_semtex *semtex);
void	semtex_unlock(t_semtex *semtex);
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
char	*new_yuitoa(int n);
void	yerror(char *msg);
void	*ycalloc(const size_t size);
void	init_thread(pthread_t *pthread, t_routine_f func, void *arg);
//	@end
#endif