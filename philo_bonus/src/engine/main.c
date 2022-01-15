#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_err		err;
	t_engine	engine;

	err = init_engine(&engine, argc, argv);
	if (err)
		return (exit_err(err));
	run_engine(&engine);
	del_engine(&engine);
	return (0);
}
