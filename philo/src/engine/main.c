#include "philosophers.h"

int	main(const int argc, const char *argv[])
{
	t_engine	e;

	init_engine(&e, argc, argv);
	run_engine(&e);
	del_engine(&e);
	return (0);
}
