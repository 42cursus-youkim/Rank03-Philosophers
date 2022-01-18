/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:08:22 by youkim            #+#    #+#             */
/*   Updated: 2022/01/17 18:52:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->pick_first);
	atomic_print_msg(philo, TAKEFORK);
	if (philo->e->flag[num_philos] == 1)
	{
		pthread_mutex_unlock(philo->pick_first);
		return ((void)msleep(philo->e->flag[time_to_die]));
	}
	pthread_mutex_lock(philo->pick_last);
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
	int					i;
	t_philo				*philo;
	const t_philoact_f	actions[4] = {
		pickup_fork, eat, sleeps, think
	};

	philo = arg;
	if (philo->id % 2)
		msleep(philo->e->flag[time_to_eat]);
	while (atomic_is_running(philo->e))
	{
		i = -1;
		while (++i < 4)
		{
			if (atomic_is_running(philo->e))
				actions[i](philo);
			else
				break ;
		}
		msleep(1);
	}
	return (NULL);
}
