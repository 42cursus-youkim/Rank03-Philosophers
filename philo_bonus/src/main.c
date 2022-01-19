#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_engine	engine;

	init_engine(&engine, argc, argv);
	if (spawn_procs(&engine) == IS_CHILD)
		philo_proc();
	engine_proc(&engine);
	return (0);
}
