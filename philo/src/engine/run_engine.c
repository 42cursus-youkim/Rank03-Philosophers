/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/22 16:26:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	del_engine(t_engine *e, int till, bool is_manager_on, t_err err)
{
	int	id;

	id = 0;
	while (++id <= till)
	{
		pthread_join(e->philos[id].thread, NULL);
		pthread_mutex_destroy(&e->forks[id]);
	}
	if (is_manager_on)
		pthread_join(e->manager, NULL);
	free(e->philos);
	free(e->forks);
	pthread_mutex_destroy(&e->enginelock);
	return (exit_err(err));
}

int	run_engine(t_engine *e)
{
	int			id;
	const int	pnum = e->flag[num_philos];

	id = 0;
	while (++id <= pnum)
		if (new_pthread(&e->philos[id].thread, routine, &e->philos[id]) != OK)
			return (del_engine(e, id, false, ERR_THREAD));
	if (new_pthread(&e->manager, manager, e) != OK)
		return (del_engine(e, pnum, true, ERR_THREAD));
	return (del_engine(e, pnum, true, OK));
}
