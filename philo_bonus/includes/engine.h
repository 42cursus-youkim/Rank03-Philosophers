#ifndef ENGINE_H
# define ENGINE_H

typedef void	*(*t_routine_f)(void *arg);
//	@func
/*
** < checks.c > */

t_err	check_argc(int argc);
void	init_flag(t_engine *e, int argc, char *argv[]);
/*
** < run_engine.c > */

void	init_philo(t_engine *e, t_philo *philo, int id);
void	init_engine(t_engine *e, int argc, char *argv[]);
void	run_engine(t_engine *e);
void	del_engine(t_engine *e);
//	@end
#endif