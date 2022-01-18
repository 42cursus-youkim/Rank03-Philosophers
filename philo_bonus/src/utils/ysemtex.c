#include "philosophers.h"

static sem_t	*try_sem_open(const char *name, int amount)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0644, amount));
}

// mutex api implemention with semaphore
void	semtex_init(t_semtex *semtex, const char *name, int amount)
{
	semtex->sem = try_sem_open(name, amount);
	if (semtex->sem == SEM_FAILED)
	{
		sem_unlink(name);
		semtex->sem = try_sem_open(name, amount);
	}
	semtex->name = new_ystr(name);
}

void	semtex_destroy(t_semtex *semtex)
{
	sem_close(semtex->sem);
	sem_unlink(semtex->name);
	free(semtex->name);
}

void	semtex_lock(t_semtex *semtex)
{
	sem_wait(semtex->sem);
}

void	semtex_unlock(t_semtex *semtex)
{
	sem_post(semtex->sem);
}
