#include "philosophers.h"

int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	if (init_engine(&engine, argc, argv) == ERR)
	{
		printf("could not initialize engine\n");
		return (1);
	}
	run_engine(&engine);
	del_engine(&engine);
	return (0);
}
