#ifndef ENGINE_H
# define ENGINE_H

typedef struct s_engine
{
	int				flag[6];
	t_semtex		forks;
	int				*pids;
	// struct s_philo	*philos;
	t_semtex		enginelock;
	struct timeval	start_time;
	bool			is_running;
}	t_engine;

typedef void	*(*t_routine_f)(void *arg);
//	@func
/*
** < checks.c > */

t_err	check_argc(int argc);
void	init_flag(t_engine *e, int argc, char *argv[]);
/*
** < run_engine.c > */

void	init_engine(t_engine *e, int argc, char *argv[]);
void	run_engine(t_engine *e);
void	del_engine(t_engine *e);
//	@end
#endif