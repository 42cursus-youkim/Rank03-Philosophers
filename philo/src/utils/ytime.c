/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ytime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <42.4.youkim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/18 17:18:44 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	getusec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * sec_in_usec + tv.tv_usec);
}

//	sleep in miliseconds
void	msleep(size_t ms)
{
	const size_t	start = getusec();

	while (getusec() - start <= ms * mili_in_usec)
		usleep(100);
}

size_t	msec_diff(struct timeval from)
{
	struct timeval	now;
	size_t			diff;

	gettimeofday(&now, NULL);
	diff = (now.tv_sec - from.tv_sec) * sec_in_mili;
	diff += (now.tv_usec - from.tv_usec) / mili_in_usec;
	return (diff);
}
