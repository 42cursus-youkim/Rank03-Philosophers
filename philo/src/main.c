/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/17 19:01:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_err		err;
	t_engine	engine;

	err = init_engine(&engine, argc, argv);
	if (err)
		return (exit_err(err));
	run_engine(&engine);
	del_engine(&engine);
	return (0);
}
