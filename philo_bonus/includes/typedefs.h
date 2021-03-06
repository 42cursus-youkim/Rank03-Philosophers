#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef enum e_res
{
	OK = 0,
	ERR = -1,
}	t_err;

typedef enum e_in_usec
{
	mili_in_usec = 1000,
	sec_in_mili = 1000,
	sec_in_usec = 1000 * mili_in_usec,
}	t_in_usec;

typedef enum e_flag
{
	num_philos = 0,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	nums_need_eat,
	nums_philos_finished_eat,
}	t_flag;

typedef enum e_state
{
	TAKEFORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_state;

typedef enum e_const
{
	IS_CHILD = 0,
}	t_const;

//	mutex implemention in semaphore
typedef struct s_ysem
{
	char	*name;
	sem_t	*sem;
}	t_ysem;

#endif