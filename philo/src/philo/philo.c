#include "philosophers.h"

// TODO: remove
#define log(msg) \
	do {										\
		pthread_mutex_lock(&philo->e->enginelock);	\
		printf("%s[%d] %zums: %s%s\n", \
		philocolor(philo), philo->id, \
		msec_diff(philo->e->start_time), msg, END);\
		pthread_mutex_unlock(&philo->e->enginelock);\
	} while (0);

#define logFork(ISTAKE, ISLEFT) \
	do { \
		pthread_mutex_lock(&philo->e->enginelock);	\
		printf("[%d] %zums: %s fork %s at <%p>\n", \
			philo->id,  msec_diff(philo->e->start_time),\
			ISTAKE ? "TAKE" : "RETURN", \
			ISLEFT ? "LEFT" : "RIGHT", \
			ISLEFT ? philo->left : philo->right);\
		pthread_mutex_unlock(&philo->e->enginelock);\
	} while (0);

static void	pickup_fork(t_philo *philo)
{
	// printf("[%d] %zu trying fork right\n", philo->id, msec_diff(philo->e->start_time));
	logFork(true, false)
	pthread_mutex_lock(philo->right);
	// atomic_print_msg(philo, TAKEFORK);
	// if (philo->e->flag[num_philos] == 1)
	// 	return ((void)msleep(philo->e->flag[time_to_die]));
	// printf("[%d] %zu trying fork right\n", philo->id, msec_diff(philo->e->start_time));
	logFork(true, true)
	pthread_mutex_lock(philo->left);
	// atomic_print_msg(philo, TAKEFORK);
}
/*
 	1
[20] [f8]
 	2

---
[2] 0ms: TAKE fork RIGHT at <0x1b6b3f8>
[2] 0ms: TAKE fork LEFT at <0x1b6b420>
0      2   is eating
[1] 200ms: TAKE fork RIGHT at <0x1b6b420>
[2] 200ms: RETURN fork LEFT at <0x1b6b420>
[2] 200ms: RETURN fork RIGHT at <0x1b6b3f8>
200    2   is sleeping
[1] 200ms: TAKE fork LEFT at <0x1b6b3f8>
200    1   is eating
[1] 400ms: RETURN fork LEFT at <0x1b6b3f8>
[1] 400ms: RETURN fork RIGHT at <0x1b6b420>
joined thread 1
joined thread 2
---

[2] [f8] 집음 -> [20] 집음
[1] [20] 집음(???)
[2] [20] 반납(????) -> [f8] 반납
[1] [f8] 집음 -> [f8] 반납 -> [20] 반납
*/
static void	eat(t_philo *philo)
{
	gettimeofday(&philo->last_eat, NULL);
	philo->eats++;
	atomic_finisheat_and_msg(philo);
	msleep(philo->e->flag[time_to_eat]);
	logFork(false, true)
	pthread_mutex_unlock(philo->left);
	logFork(false, false)
	pthread_mutex_unlock(philo->right);
}

static void	sleeps(t_philo *philo)
{
	atomic_print_msg(philo, SLEEPING);
	msleep(philo->e->flag[time_to_sleep]);
}

static void	think(t_philo *philo)
{
	atomic_print_msg(philo, THINKING);
}

typedef void	(*t_action)(t_philo *);

void	*routine(void *arg)
{
	t_philo	*philo;
	t_action	actions[4] = {pickup_fork, eat, sleeps, think};
	// char *logs[4] = {
	// 	"start fork",
	// 	"end fork && start eat",
	// 	"end eat && start sleep",
	// 	"end sleep && start think"
	// };
	philo = arg;
	if (philo->id % 2)
		msleep(philo->e->flag[time_to_eat]);
	while (atomic_is_running(philo->e))
	{
		for (int i = 0; i < 4; i++)
		{
			if (!atomic_is_running(philo->e))
				break;
			else
			{
				// log(logs[i]);
				actions[i](philo);
			}
		}
	}
	// while (philo->e->is_running)
	// {
	// 	log("start fork")
	// 	if (!philo->e->is_running)
	// 		break ;
	// 	pickup_fork(philo);
	// 	log("end fork && start eat")
	// 	if (!philo->e->is_running)
	// 		break ;
	// 	log("end eat && start sleep")
	// 	if (!philo->e->is_running)
	// 		break ;
	// 	log("end sleep && start think")
	// 	if (!philo->e->is_running)
	// 		break ;
	// 	log("end think")
	// }
	// log("ok i'm die thank you fore ver")
	return (NULL);
}
