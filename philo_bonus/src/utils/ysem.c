#include "philosophers.h"

static sem_t	*try_sem_open(const char *name, int amount)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0644, amount));
}

// mutex api implemention with semaphore
void	new_ysem(t_ysem *ysem, char *name, int amount)
{
	ysem->sem = try_sem_open(name, amount);
	if (ysem->sem == SEM_FAILED)
	{
		sem_unlink(name);
		ysem->sem = try_sem_open(name, amount);
	}
	ysem->name = new_ystr(name);
}

void	del_ysem(t_ysem *ysem)
{
	sem_close(ysem->sem);
	sem_unlink(ysem->name);
	free(ysem->name);
}

//	-1, to value, actually
void	ysem_lock(t_ysem *ysem)
{
	sem_wait(ysem->sem);
}

// 	+1 to value, actually
void	ysem_unlock(t_ysem *ysem)
{
	sem_post(ysem->sem);
}
