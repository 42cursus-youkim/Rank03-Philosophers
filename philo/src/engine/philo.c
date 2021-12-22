#include "philo.h"
#include <string.h>

int main(void)
{
	int result[2];
	pthread_t pthread;

	new_thread(&pthread, p_function, "thread 1");
	new_thread(&pthread, p_function, "thread 2");
	pthread_join(pthread, (void *)&result[0]);
	pthread_join(pthread, (void *)&result[1]);
	printf("results: [0]:%d, [1]:%d\n", result[0], result[1]);
	printf("end\n");
	return 0;
}
