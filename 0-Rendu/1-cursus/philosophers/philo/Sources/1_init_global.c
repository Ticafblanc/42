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

#include <philo.h>

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
		if (pthread_mutex_init(&(philo[id]->fork), NULL))
			return (5);
		philo[id]->philo_id = id;
		philo[id]->global = (*global);
		philo[id]->statut = THINK;
		philo[id]->number_eat = 0;
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
		(*global)->number_of_times_each_philosopher_must_eat
			= fill_data(argv[5]) * (*global)->number_of_philosophers;
	else
		(*global)->number_of_times_each_philosopher_must_eat = -1;
	if ((*global)->number_of_philosophers < 1 || (*global)->time_to_die < 0
		|| (*global)->time_to_eat < 0 || (*global)->time_to_sleep < 0)
		return (2);
	if (pthread_mutex_init(&((*global)->print), NULL))
		return (5);
	return (init_philo(global));
}
