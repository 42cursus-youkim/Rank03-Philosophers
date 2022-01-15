#include "philosophers.h"

void child_proc(t_semtex *semtex)
{
	semtex_lock(semtex);
	printf("[child] semtex locked\n");
	printf("[child] semtex address at %p\n", semtex->sem);
	sleep(1);
	semtex_unlock(semtex);
	printf("[child] semtex unlocked\n");
	printf("[child] ok i'm die thank you forever\n");
}

void parent_proc(t_semtex *semtex)
{
	usleep(100);
	semtex_lock(semtex);
	printf("[parent] semtex locked\n");
	printf("[parent] semtex address at %p\n", semtex->sem);
	sleep(1);
	semtex_unlock(semtex);
	printf("[parent] semtex unlocked\n");
	waitpid(0, NULL, 0);
	printf("[parent] child process terminated\n");
	semtex_destroy(semtex);
}

int	main(void) // int argc, char *argv[]
{
	t_semtex	semtex;
	pid_t		pid;

	semtex_init(&semtex, "/philosophers", 1);
	pid = fork();
	if (pid == 0)
	{
		child_proc(&semtex);
	}
	else
	{
		parent_proc(&semtex);
	}
	return (0);
}

	// t_err		err;
	// t_engine	engine;

	// err = init_engine(&engine, argc, argv);
	// if (err)
	// 	return (exit_err(err));
	// run_engine(&engine);
	// del_engine(&engine);