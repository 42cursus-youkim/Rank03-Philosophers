/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yatomic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:14:15 by youkim            #+#    #+#             */
/*   Updated: 2022/01/22 15:17:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	atomic_is_running(t_engine *e)
{
	bool	ret;

	pthread_mutex_lock(&e->enginelock);
	ret = e->is_running;
	pthread_mutex_unlock(&e->enginelock);
	return (ret);
}

/*	increase the number of philosophers who finished eating.
	variable race condition protected with mutex[e->lock].
*/
void	atomic_finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->e->enginelock);
	if (philo->eats == philo->e->flag[nums_need_eat])
		philo->e->flag[nums_philos_finished_eat]++;
	pthread_mutex_unlock(&philo->e->enginelock);
}

void	atomic_stop_running(t_engine *e)
{
	pthread_mutex_lock(&e->enginelock);
	e->is_running = false;
	pthread_mutex_unlock(&e->enginelock);
}
