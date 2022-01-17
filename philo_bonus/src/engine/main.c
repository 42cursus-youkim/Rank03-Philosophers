#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_engine	engine;

	init_engine(&engine, argc, argv);
	run_engine(&engine);
	del_engine(&engine);
}