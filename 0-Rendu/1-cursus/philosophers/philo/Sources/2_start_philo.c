/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_start_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:09:32 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/22 14:09:35 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*start_time(void *global_void)
{
	t_global	*global;
	long long	timestamp_start;

	global = (t_global *)global_void;
	global->statut = ON;
	timestamp_start = ft_timestamp();
	while (global->stat == ON)
	{
		global->timestamp = ft_timestamp() - timestamp_start;
		usleep(100);
	}
	return (0);
}

static void	loop_philo_next(t_philo *philo)
{
	put_philo(philo, philo->statut);
	if (philo->statut == EAT || philo->statut == SLEEP)
		sleep_check(philo->global, philo->statut);
	if (philo->statut == THINK && philo->global->statut == ALIVE)
		own_fork(philo->global, philo->philo_id);
	else if (philo->statut == OWN_FORK && philo->global->statut == ALIVE)
		right_fork(philo->global, philo->philo_id);
	else if (philo->statut == RIGHT_FORK && philo->global->statut == ALIVE)
		eat_philo(philo);
	else if (philo->statut == EAT && philo->global->statut == ALIVE)
		sleep_philo(philo);
	else if (philo->statut == SLEEP && philo->global->statut == ALIVE)
		philo->statut = THINK;
}

void	*loop_philo(void *philo_void)
{
	t_philo		*philo;

	philo = (t_philo *)philo_void;
	philo->last_meal_timestamp = philo->global->timestamp;
	if (philo->philo_id % 2)
		usleep(15000);
	else
		own_fork(philo->global, philo->philo_id);
	while (philo->global->statut == ALIVE)
	{
		loop_philo_next(philo);
	}
	free_fork(philo->global, philo->philo_id);
	return (0);
}

void	start_philo(t_global *global)
{
	t_philo	**philo;
	int		id;

	philo = global->philo;
	id = 0;
	global->statut = ALIVE;
	while (id < global->number_of_philosophers)
	{
		pthread_create(&(philo[id]->thread_id), NULL, loop_philo, philo[id]);
		pthread_detach(global->philo[id]->thread_id);
		id++;
	}
	return ;
}
