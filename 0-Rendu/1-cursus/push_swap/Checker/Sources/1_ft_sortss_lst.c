/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_sortss_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/23 17:20:55 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_sortss_lst(int i, t_mem *save)
{
	if (ft_sortss1_lst(i, save) == 2)
		return (2);
	if (ft_sortss2_lst(i, save) == 2)
		return (2);
	if (ft_sortss3_lst(i, save) == 2)
		return (2);
	if (ft_sortss4_lst(i, save) == 2)
		return (2);
	return (0);
}

int	ft_sortss1_lst(int i, t_mem *save)
{
	if (i == 40)
	{
		if (save->index_a < 2)
			return (2);
		ft_sa(save);
	}
	else if (i == 60)
	{
		if (save->index_b < 2)
			return (2);
		ft_sb(save);
	}
	else if (i == 400)
	{
		if (save->index_b < 2 || save->index_a < 2)
			return (2);
		ft_ss(save);
	}
	return (0);
}

int	ft_sortss2_lst(int i, t_mem *save)
{
	if (i == 20)
	{
		if (save->index_b < 1)
			return (2);
		ft_pa(save);
	}
	else if (i == 30)
	{
		if (save->index_a < 1)
			return (2);
		ft_pb(save);
	}
	else if (i == 80)
	{
		if (save->index_a < 2)
			return (2);
		ft_ra(save);
	}
	return (0);
}

int	ft_sortss3_lst(int i, t_mem *save)
{
	if (i == 120)
	{
		if (save->index_b < 2)
			return (2);
		ft_rb(save);
	}
	else if (i == 1600)
	{
		if (save->index_b < 2 || save->index_a < 2)
			return (2);
		ft_rr(save);
	}
	else if (i == 3200)
	{
		if (save->index_a < 2)
			return (2);
		ft_rra(save);
	}
	return (0);
}

int	ft_sortss4_lst(int i, t_mem *save)
{
	if (i == 4800)
	{
		if (save->index_b < 2)
			return (2);
		ft_rrb(save);
	}
	else if (i == 64000)
	{
		if (save->index_b < 2 || save->index_a < 2)
			return (2);
		ft_rrr(save);
	}
	return (0);
}
