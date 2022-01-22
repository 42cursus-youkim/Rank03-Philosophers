/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/22 15:41:06 by youkim           ###   ########.fr       */
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
	return (run_engine(&engine));
}
