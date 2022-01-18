/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:08:22 by youkim            #+#    #+#             */
/*   Updated: 2022/01/17 19:02:48 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int				id;
	int				eats;
	pthread_t		thread;
	pthread_mutex_t	*pick_first;
	pthread_mutex_t	*pick_last;
	struct s_engine	*e;
	struct timeval	last_eat;
}	t_philo;

//	@func
/*
** < manager.c > */

void	*manager(void *arg);
/*
** < philo.c > */

void	*routine(void *arg);
#endif