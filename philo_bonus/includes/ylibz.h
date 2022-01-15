#ifndef YLIBZ_H
# define YLIBZ_H

//	@func
/*
** < yutils.c > */

void	yerror(char *where, char *msg);
void	*ycalloc(const size_t size);
/*
** < ystr.c > */

char	*new_ystr(const char *from);
char	*new_ystrm(int length);
int		ystrlen(const char *str);
int		ystrcpy(char *dst, const char *src);
int		ystr_append(char **pstr, char *src);
#endif