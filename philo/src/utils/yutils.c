/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:08:22 by youkim            #+#    #+#             */
/*   Updated: 2022/01/22 16:26:21 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_err	yatoui(const char *str, int *n)
{
	int	i;

	i = 0;
	*n = 0;
	if (!str || str[0] == '-')
		return (ERR_ARG);
	while ('0' <= str[i] && str[i] <= '9')
		(*n) = (*n) * 10 + (str[i++] - '0');
	return (OK);
}

//	uses internal memset
void	*ycalloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (memset(ptr, 0, size));
}

int	exit_err(t_err err)
{
	const char	*err_msg[] = {
		"NOT AN ERROR",
		"Usage: ./philosophers\
		num_philos time_to_die time_to_eat time_to_sleep [nums_need_eat]",
		"cannot convert given argument to non-negative integer",
		"failed to allocate memory",
		"invalid number of philosophers",
		"could not initialize mutex",
		"could not initialize thread",
	};
	if (err == OK)
		return (0);
	printf("%s\n", err_msg[err]);
	return (1);
}

int	new_pthread(pthread_t *thread, t_routine_f routine, void *arg)
{
	return pthread_create(thread, NULL, routine, arg);
}
