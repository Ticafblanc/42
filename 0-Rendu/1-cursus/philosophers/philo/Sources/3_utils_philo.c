/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_utils_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:09:41 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/22 14:09:43 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	right_fork(t_global	*global, int philo_id)
{
	t_philo		*philo_right;

	if (philo_id == global->number_of_philosophers - 1)
		philo_right = global->philo[0];
	else
		philo_right = global->philo[philo_id + 1];
	pthread_mutex_lock(&(philo_right->fork));
	global->philo[philo_id]->statut = RIGHT_FORK;
}

void	own_fork(t_global	*global, int philo_id)
{
	t_philo		*philo;

	philo = global->philo[philo_id];
	pthread_mutex_lock(&(philo->fork));
	global->philo[philo_id]->statut = OWN_FORK;
}

void	eat_philo(t_philo *philo)
{
	philo->statut = EAT;
	philo->last_meal_timestamp = philo->global->timestamp;
	if (philo->global->number_of_times_each_philosopher_must_eat > 0)
		philo->global->number_of_times_each_philosopher_must_eat--;
}

void	sleep_philo(t_philo *philo)
{
	t_philo		*philo_right;

	philo->statut = SLEEP;
	pthread_mutex_unlock(&(philo->fork));
	if (philo->philo_id == philo->global->number_of_philosophers - 1)
		philo_right = philo->global->philo[0];
	else
		philo_right = philo->global->philo[philo->philo_id + 1];
	pthread_mutex_unlock(&(philo_right->fork));
}

void	free_fork(t_global	*global, int philo_id)
{
	pthread_mutex_unlock(&(global->philo[philo_id]->fork));
	if (philo_id == global->number_of_philosophers - 1)
		pthread_mutex_unlock(&global->philo[0]->fork);
	else
		pthread_mutex_unlock(&global->philo[philo_id + 1]->fork);
}
