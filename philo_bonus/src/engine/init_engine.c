#include "philosophers.h"

// void	init_philosopher(t_engine *e, int id, t_philo *philo)
// {
// 	// char	*semtex_num;
// 	// char	*semtex_name;

// 	philo->e = e;
// 	philo->id = id;
// 	philo->left = &e->forks[id];
// 	if (id == e->flag[num_philos])
// 		philo->right = &e->forks[1];
// 	else
// 		philo->right = &e->forks[id + 1];
// 	philo->last_eat = e->start_time;
// 	// semtex_num = new_yuitoa(id);
// 	// semtex_name = new_ystr("philosopher");
// 	// ystr_append(&semtex_name, semtex_num);
// 	// new_semtex(&philo->lock, semtex_name, 1);
// }

/*	allocate memory for philosophers and forks. id starts from 1.
*/
void	init_engine(t_engine *e, int argc, char *argv[])
{
	int		id;

	init_flag(e, argc, argv);
	new_semtex(&e->enginelock, "engine", 1);
	new_semtex(&e->forks, "forks", e->flag[num_philos]);
	// e->philos = ycalloc((e->flag[num_philos] + 1) * sizeof(t_philo));
	id = 0;
	// while (++id <= e->flag[num_philos])
	// {
	// 	init_mutex(&e->forks[id]);
	// 	init_philosopher(e, id, &e->philos[id]);
	// }
}
