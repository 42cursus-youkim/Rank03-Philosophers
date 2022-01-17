/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <42.4.youkim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:21:37 by youkim            #+#    #+#             */
/*   Updated: 2022/01/15 14:21:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//	===== library =====
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

//	===== philosophers =====
# include "enums.h"
# include "philo.h"
# include "engine.h"
# include "utils.h"
# include "colors.h"

#endif