#ifndef YLIBZ_H
# define YLIBZ_H

//	@func
/*
** < ystr.c > */

char	*new_ystr(const char *from);
char	*new_ystrm(int length);
int		ystrlen(const char *str);
int		ystrcpy(char *dst, const char *src);
int		ystr_append(char **pstr, char *src);
/*
** < yutils.c > */

t_err	yatoui(const char *str, int *n);
void	yerror(char *msg);
void	*ycalloc(const size_t size);
#endif