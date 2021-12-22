#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//	===== utils =====
# include <errno.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>

//	===== logging =====
# include <stdio.h>
# include <unistd.h>

//	===== thread =====
# include <pthread.h>

//	===== philosophers =====
# include "engine.h"
# include "philo.h"
# include "utils.h"

#endif