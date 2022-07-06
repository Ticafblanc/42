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

#include <philo_bonus.h>

static void	loop_philo_next(t_philo *philo)
{
	put_philo(philo, philo->statut);
	if (philo->statut == EAT || philo->statut == SLEEP)
		sleep_check(philo);
	if (philo->statut == THINK)
		one_fork(philo->global, philo->philo_id);
	else if (philo->statut == ONE_FORK)
		two_fork(philo->global, philo->philo_id);
	else if (philo->statut == TWO_FORK)
		eat_philo(philo);
	else if (philo->statut == EAT)
		sleep_philo(philo);
	else if (philo->statut == SLEEP)
		philo->statut = THINK;
}

void	loop_philo(void *philo_void)
{
	t_philo		*philo;

	philo = (t_philo *)philo_void;
	philo->last_meal_timestamp = ft_timestamp();
	pthread_create(&(philo->thread_id), NULL, loop_healt, philo);
	if (philo->philo_id % 2)
		usleep(15000);
	else
		one_fork(philo->global, philo->philo_id);
	while (philo->statut != DEAD && philo->statut != DONE)
	{
		loop_philo_next(philo);
	}
	pthread_join(philo->thread_id, NULL);
	if (philo->statut == DEAD)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	start_philo(t_global *global)
{
	t_philo	**philo;
	int		id;

	philo = global->philo;
	id = 0;
	global->start_time = ft_timestamp();
	while (id < global->number_of_philosophers)
	{
		philo[id]->pid_id = fork();
		if (philo[id]->pid_id == 0)
			loop_philo(philo[id]);
		id++;
	}
	return ;
}
