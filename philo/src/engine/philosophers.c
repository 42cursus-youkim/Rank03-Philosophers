#include "philosophers.h"

int	main(const int argc, const char *argv[])
{
	t_engine	e;

	init_flag(&e, argc, argv);
	init_engine(&e);
	return (0);
}
