/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <42.4.youkim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:08:22 by youkim            #+#    #+#             */
/*   Updated: 2022/01/18 16:14:07 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->pick_first);
	if (!atomic_is_running(philo->e))
	{
		pthread_mutex_unlock(philo->pick_first);
		return ;
	}
	atomic_print_msg(philo, TAKEFORK);
	if (philo->e->flag[num_philos] == 1)
	{
		pthread_mutex_unlock(philo->pick_first);
		return ((void)msleep(philo->e->flag[time_to_die]));
	}
	pthread_mutex_lock(philo->pick_last);
	if (!atomic_is_running(philo->e))
	{
		pthread_mutex_unlock(philo->pick_last);
		pthread_mutex_unlock(philo->pick_first);
		return ;
	}
	atomic_print_msg(philo, TAKEFORK);
}

static void	eat(t_philo *philo)
{
	gettimeofday(&philo->last_eat, NULL);
	philo->eats++;
	atomic_finish_eating(philo);
	atomic_print_msg(philo, EATING);
	msleep(philo->e->flag[time_to_eat]);
	pthread_mutex_unlock(philo->pick_last);
	pthread_mutex_unlock(philo->pick_first);
}

static void	sleeps(t_philo *philo)
{
	atomic_print_msg(philo, SLEEPING);
	msleep(philo->e->flag[time_to_sleep]);
}

static void	think(t_philo *philo)
{
	atomic_print_msg(philo, THINKING);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2)
		msleep(philo->e->flag[time_to_eat]);
	while (atomic_is_running(philo->e))
	{
		pickup_fork(philo);
		eat(philo);
		sleeps(philo);
		think(philo);
		usleep(100);
		// msleep(1);
	}
	return (NULL);
}
