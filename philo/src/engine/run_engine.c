/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/17 19:01:01 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	run_engine(t_engine *e)
{
	int			id;

	id = 0;
	while (++id <= e->flag[num_philos])
		pthread_create(
			&e->philos[id].thread, NULL, routine, &e->philos[id]);
	pthread_create(&e->manager, NULL, manager, e);
}

void	del_engine(t_engine *e)
{
	int			id;

	id = 0;
	while (++id <= e->flag[num_philos])
		pthread_join(e->philos[id].thread, NULL);
	id = 0;
	while (++id <= e->flag[num_philos])
		pthread_mutex_destroy(&e->forks[id]);
	free(e->forks);
	free(e->philos);
	pthread_join(e->manager, NULL);
	pthread_mutex_destroy(&e->enginelock);
}
