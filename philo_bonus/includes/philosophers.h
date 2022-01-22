#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//	===== library =====
# include <unistd.h>
# include <stdbool.h>

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>

// ===== types =====
# include <fcntl.h>

//	===== philosophers =====
# include "typedefs.h"
# include "process.h"
# include "engine.h"
# include "utils.h"
# include "colors.h"
# include "ylibz.h"

#endif