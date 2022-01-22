#include "philosophers.h"

void	engine_proc(t_engine *e)
{
	int	id;

	id = 0;
	while (++id <= e->flag[num_philos])
		waitpid(e->philos[id].pid, NULL, 0);
	printf("자식 프로세스 모두 끝\n");
	printf("부모 pid는 %d\n", getpid());
	del_engine(e);
	exit(0);
}
