/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:08:22 by youkim            #+#    #+#             */
/*   Updated: 2022/01/22 16:19:39 by youkim           ###   ########.fr       */
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
** < checks.c > */

t_err	check_argc(int argc);
t_err	init_flag(t_engine *e, int argc, char *argv[]);
/*
** < init_engine.c > */

void	init_philosopher(t_engine *e, int id, t_philo *philo);
t_err	init_engine(t_engine *e, int argc, char *argv[]);
/*
** < run_engine.c > */

int		run_engine(t_engine *e);
//	@end
#endif