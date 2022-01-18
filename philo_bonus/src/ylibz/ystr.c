#include "philosophers.h"

/*	copy a string. equivalent to strdup()
	use NULL TERMINATED STRING if you'r passing it implicitly!!!
*/
char	*new_ystr(const char *from)
{
	int		i;
	char	*str;

	i = ystrlen(from);
	str = new_ystrm(i);
	if (!str)
		return (NULL);
	while (i-- > 0)
		str[i] = from[i];
	return (str);
}

/*	create an NULL-terminated malloced string.
	use when you'll manualy use loop to set the string.
	returns NULL if allocation failed or length is below zero.
*/
char	*new_ystrm(int length)
{
	char	*str;

	if (length < 0)
		return (NULL);
	str = ycalloc((length + 1) * sizeof(char));
	str[length] = '\0';
	return (str);
}

//	length of a string. null termination is not counted.
int	ystrlen(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

//	returns length of strings appended.
int	ystrcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (ystrlen(src));
}

/*	looks like strjoin but is memory safe, by replacing the original string
	returns: length of joined string, usage: ystr_append(&str, STRING)
*/
int	ystr_append(char **pstr, char *src)
{
	const int	org_len = ystrlen(*pstr);
	const int	src_len = ystrlen(src);
	const int	new_len = org_len + src_len;
	char		*new;

	new = new_ystrm(new_len);
	ystrcpy(new, *pstr);
	ystrcpy(new + org_len, src);
	free(*pstr);
	*pstr = new;
	return (new_len);
}