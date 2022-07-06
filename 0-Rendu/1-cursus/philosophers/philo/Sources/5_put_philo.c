/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_put_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:10:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/06/22 14:10:41 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	put_success(t_philo *philo, int statut)
{
	pthread_mutex_lock(&philo->global->print);
	if (statut == DEAD)
		printf("%d %d died\n", philo->global->timestamp, philo->philo_id);
	else if (statut == DONE)
		printf("done\n");
	philo->global->stat = OFF;
	pthread_mutex_unlock(&philo->global->print);
}

int	put_philo(t_philo *philo, int statut)
{
	if (philo->global->statut != ALIVE)
		return (0);
	pthread_mutex_lock(&philo->global->print);
	if ((statut == OWN_FORK || statut == RIGHT_FORK)
		&& philo->global->statut == ALIVE)
		printf("%d %d has taken a fork\n",
			philo->global->timestamp, philo->philo_id);
	else if (statut == EAT && philo->global->statut == ALIVE)
		printf("%d %d is eating\n", philo->global->timestamp, philo->philo_id);
	else if (statut == SLEEP && philo->global->statut == ALIVE)
		printf("%d %d is sleeping\n", philo->global->timestamp, philo->philo_id);
	else if (statut == THINK && philo->global->statut == ALIVE)
		printf("%d %d is thinking\n", philo->global->timestamp, philo->philo_id);
	pthread_mutex_unlock(&philo->global->print);
	return (0);
}

int	put_error(int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("erreur argument\n", 2);
		ft_putstr_fd("argument:	-number_of_philosophers\n", 2);
		ft_putstr_fd("		-time_to_die\n", 2);
		ft_putstr_fd("		-time_to_eat\n", 2);
		ft_putstr_fd("		-time_to_sleep\n", 2);
		ft_putstr_fd(" (option)	-number_of_times_each_philosopher_must_eat", 2);
	}
	if (flag == 1)
		ft_putstr_fd("fail init global", 2);
	if (flag == 3 || flag == 4)
		ft_putstr_fd("fail init philo", 2);
	if (flag == 5)
		ft_putstr_fd("fail init mutex", 2);
	if (flag == 6)
		ft_putstr_fd("fail init thread", 2);
	return (EXIT_FAILURE);
}

int	free_philo_2(t_global *global, int flag)
{
	if (flag >= 4)
	{
		ft_free_pp((void **)global->philo);
		free (global);
		return (put_error(flag));
	}
	if (flag == 7 || flag == 8)
	{
		ft_mutex_destroy(global);
		ft_free_pp((void **)global->philo);
		free (global);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	free_philo(t_global *global, int flag)
{
	if (flag == 1)
		return (put_error(flag));
	if (flag == 2)
	{
		free (global);
		return (put_error(0));
	}
	if (flag == 3)
	{
		free (global);
		return (put_error(flag));
	}
	return (free_philo_2(global, flag));
}
