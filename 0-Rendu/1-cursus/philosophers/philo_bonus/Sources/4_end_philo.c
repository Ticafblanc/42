/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_end_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:09:50 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/22 14:09:53 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	sleep_check(t_philo *philo)
{
	long long	end_time;

	if (philo->statut == EAT)
	{
		end_time = ft_timestamp() + philo->global->time_to_eat;
		while (philo->statut != DONE && philo->statut != DEAD
			&& end_time > ft_timestamp())
			usleep(100);
	}
	else if (philo->statut == SLEEP)
	{
		end_time = philo->global->time_to_sleep + ft_timestamp();
		while (philo->statut != DONE && philo->statut != DEAD
			&& end_time > ft_timestamp())
			usleep(100);
	}
}

void	*loop_healt(void *philo_void)
{
	t_philo	*philo;

	philo = philo_void;
	while (philo->statut != DEAD && philo->statut != DONE)
	{
		if ((philo->last_meal_timestamp + philo->global->time_to_die)
			< ft_timestamp ())
			philo->statut = DEAD;
		if (philo->number_eat == 0)
			philo->statut = DONE;
		if (philo->statut == DONE || philo->statut == DEAD)
			break ;
		usleep(1000);
	}
	if (philo->statut == DEAD)
	{
		sem_wait(philo->global->prints);
		printf("%lld %d died\n", ft_timestamp()
			- philo->global->start_time, philo->philo_id);
		exit (EXIT_FAILURE);
	}
	return (0);
}

static void	ft_close(t_global *global)
{
	sem_close(global->priority);
	sem_close(global->forks);
	sem_close(global->prints);
	sem_unlink("sem_priority");
	sem_unlink("sem_prints");
	sem_unlink("sem_forks");
}

int	wait_philo(t_global *global)
{
	int		id;
	int		status;

	id = 0;
	while (id < global->number_of_philosophers)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			id = -1;
			while (++id < global->number_of_philosophers)
				kill(global->philo[id]->pid_id, SIGKILL);
		}
		id++;
	}
	if (status == 0)
		printf("done\n");
	ft_close(global);
	return (7);
}
