#include "philosophers.h"

//	ascii to unsigned int
t_err	yatoui(const char *str, int *n)
{
	int	i;

	i = 0;
	*n = 0;
	if (!str || str[0] == '-')
		return (ERR);
	while ('0' <= str[i] && str[i] <= '9')
		(*n) = (*n) * 10 + (str[i++] - '0');
	return (OK);
}

//	unsigned int to ascii
char	*new_yuitoa(int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (new_ystr("0"));
	else if (n < 0)
		yerror("yuitoa: negative number");
	i = 0;
	str = ycalloc(n);
	while (n > 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

//	do not use after fork()! it would only close one procoess
void	yerror(char *msg)
{
	printf("%s[Error]\n    %s%s\n", BHRED, msg, END);
	exit(1);
}

//	uses memset
void	*ycalloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		yerror("failed to allocate memory");
	return (memset(ptr, 0, size));
}

void	init_thread(pthread_t *pthread, t_routine_f func, void *arg)
{
	const int	res = pthread_create(pthread, NULL, func, arg);

	if (res == OK)
		return ;
	yerror("could not initialize thread");
}
