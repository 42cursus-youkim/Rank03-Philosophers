/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/15 14:21:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_res
{
	OK = 0,
	ERR_ARG,
	ERR_NUM,
	ERR_MEM,
	ERR_PHILO,
}	t_err;

typedef enum e_in_usec
{
	mili_in_usec = 1000,
	sec_in_mili = 1000,
	sec_in_usec = 1000 * mili_in_usec,
}	t_in_usec;

typedef enum e_flag
{
	num_philos = 0,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	nums_need_eat,
	nums_philos_finished_eat,
}	t_flag;

typedef enum s_state
{
	TAKEFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_state;

#endif