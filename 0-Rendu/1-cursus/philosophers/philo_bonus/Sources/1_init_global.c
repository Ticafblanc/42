/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:07:19 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/22 14:07:23 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	init_philo(t_global **global)
{
	int		id;
	t_philo	**philo;

	id = 0;
	(*global)->philo = (t_philo **)malloc
		(((*global)->number_of_philosophers + 1) * sizeof(t_philo *));
	if (!(*global)->philo)
		return (3);
	philo = (*global)->philo;
	while (id < (*global)->number_of_philosophers)
	{
		philo[id] = (t_philo *)malloc(sizeof(t_philo));
		if (!((*global)->philo[id]))
			return (4);
		philo[id]->philo_id = id;
		philo[id]->global = (*global);
		philo[id]->statut = THINK;
		if ((*global)->number_of_times_each_philosopher_must_eat > 0)
			philo[id]->number_eat = (*global)
				->number_of_times_each_philosopher_must_eat;
		else
			philo[id]->number_eat = -1;
		id++;
	}
	return (0);
}

int	fill_data(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			i++;
		else
			return (-1);
	}
	return (ft_atol(argv));
}

static void	init_sem(t_global **global)
{
	sem_unlink("sem_priority");
	(*global)->priority = sem_open("sem_priority", O_CREAT, S_IRWXU,
			(*global)->number_of_philosophers);
	sem_unlink("sem_prints");
	(*global)->prints = sem_open("sem_prints", O_CREAT, S_IRWXU, 1);
	sem_unlink("sem_forks");
	(*global)->forks = sem_open("sem_forks", O_CREAT, S_IRWXU,
			(*global)->number_of_philosophers);
}

int	init_global(t_global **global, char **argv)
{
	(*global) = (t_global *)malloc(sizeof(t_global));
	if (!(*global))
		return (1);
	(*global)->number_of_philosophers = fill_data(argv[1]);
	(*global)->time_to_die = fill_data(argv[2]);
	(*global)->time_to_eat = fill_data(argv[3]);
	(*global)->time_to_sleep = fill_data(argv[4]);
	if (argv[5])
	{
		(*global)->number_of_times_each_philosopher_must_eat
			= fill_data(argv[5]);
		if ((*global)->number_of_times_each_philosopher_must_eat == -1)
			return (2);
	}
	else
		(*global)->number_of_times_each_philosopher_must_eat = -1;
	if ((*global)->number_of_philosophers < 1 || (*global)->time_to_die < 0
		|| (*global)->time_to_eat < 0 || (*global)->time_to_sleep < 0)
		return (2);
	init_sem(global);
	return (init_philo(global));
}
