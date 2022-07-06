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

#include <philo_bonus.h>

void	put_success(t_philo *philo)
{
	sem_wait(philo->global->prints);
	if (philo->statut == DEAD)
		printf("%lld %d died\n", ft_timestamp()
			- philo->global->start_time, philo->philo_id);
}

int	put_philo(t_philo *philo, int statut)
{
	if (philo->statut == DEAD || philo->statut == DONE)
		return (0);
	sem_wait(philo->global->prints);
	if ((statut == ONE_FORK || statut == TWO_FORK)
		&& philo->statut != DEAD && philo->statut != DONE)
		printf("%lld %d has taken a fork\n",
			ft_timestamp() - philo->global->start_time, philo->philo_id);
	else if (statut == EAT
		&& philo->statut != DEAD && philo->statut != DONE)
		printf("%lld %d is eating\n", ft_timestamp()
			- philo->global->start_time, philo->philo_id);
	else if (statut == SLEEP
		&& philo->statut != DEAD && philo->statut != DONE)
		printf("%lld %d is sleeping\n", ft_timestamp()
			- philo->global->start_time, philo->philo_id);
	else if (statut == THINK
		&& philo->statut != DEAD && philo->statut != DONE)
		printf("%lld %d is thinking\n", ft_timestamp()
			- philo->global->start_time, philo->philo_id);
	sem_post(philo->global->prints);
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
