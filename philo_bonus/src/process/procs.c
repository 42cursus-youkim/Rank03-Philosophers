#include "philosophers.h"

#define PRINTARR(size, arr) \
	for (int i = 0; i < size; i++) \
		printf("%d ", arr[i]); \
	printf("\n");


void	philo_proc(void)
{
	int pid = getpid(); //	TODO: getpid() 지우기
	printf("안녀ㅕㅕㅕㅇ, 내 pid는 %d\n", pid);
	exit(0);
}

void	engine_proc(t_engine *e)
{
	int	id;

	id = 0;
	while (++id < e->flag[num_philos])
		waitpid(e->pids[id], NULL, 0);
	printf("자식 프로세스 모두 끝\n");
	printf("부모 pid는 %d\n", getpid());
	printf("자식 프로세스 번호들은 => ");
	PRINTARR(e->flag[num_philos], e->pids);
	del_engine(e);
	exit(0);
}
