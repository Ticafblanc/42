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

#include <philo_bonus.h>

void	two_fork(t_global	*global, int philo_id)
{
	sem_wait(global->forks);
	sem_post(global->priority);
	global->philo[philo_id]->statut = TWO_FORK;
}

void	one_fork(t_global *global, int philo_id)
{
	sem_wait(global->priority);
	sem_wait(global->forks);
	global->philo[philo_id]->statut = ONE_FORK;
}

void	eat_philo(t_philo *philo)
{
	philo->statut = EAT;
	philo->last_meal_timestamp = ft_timestamp();
}

void	sleep_philo(t_philo *philo)
{
	if (philo->global->number_of_times_each_philosopher_must_eat > 0)
		philo->number_eat--;
	philo->statut = SLEEP;
	sem_post(philo->global->forks);
	sem_post(philo->global->forks);
}
