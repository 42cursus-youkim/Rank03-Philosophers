/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:08:22 by youkim            #+#    #+#             */
/*   Updated: 2022/01/17 19:02:48 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_engine
{
	int				flag[6];
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		manager;
	bool			is_running;
	pthread_mutex_t	enginelock;
	struct timeval	start_time;
}	t_engine;

typedef void	*(*t_routine_f)(void *arg);
typedef void	(*t_philoact_f)(t_philo *);

//	@func
/*
** < run_engine.c > */

void	run_engine(t_engine *e);
void	del_engine(t_engine *e);
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
t_err	init_engine(t_engine *e, int argc, char *argv[]);
/*
** < checks.c > */

t_err	check_argc(int argc);
t_err	init_flag(t_engine *e, int argc, char *argv[]);
//	@end
#endif