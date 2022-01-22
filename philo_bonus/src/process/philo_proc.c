#include "philosophers.h"

// static void	pickup_fork(t_philo *philo)
// {

// }

void	philo_proc(t_philo *philo)
{
	// int pid = getpid(); //	TODO: getpid() 지우기
	ysem_lock(&philo->e->forks);
	printf("[%d] 포크 잡음\n", philo->id);
	sleep(1);
	ysem_unlock(&philo->e->forks);
	// printf("e:%p, id:%d, 마지막 식사 시간:%ld\n", philo->e, philo->id, philo->last_eat.tv_sec);
	printf("잘가ㅏㅏㅏㅏ\n");
	// while (true)
	// {

	// }
	exit(0);
}
