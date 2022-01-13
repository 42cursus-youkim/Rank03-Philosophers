#include "philosophers.h"

int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	init_engine(&engine, argc, argv);
	run_engine(&engine);
	del_engine(&engine);
	return (0);
}
