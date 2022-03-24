/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.0_ft_sort_gr_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/08 12:18:22 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_gr(t_mem *save)
{
	save->n_gr = 0;
	while (save->n_gr++ != save->int_n_gr && save->index_a > 0)
	{
		save->rr = 0;
		save->rrp = 0;
		ft_sch_nb_a(save);
		ft_start_rra(save);
		ft_while_gr_a(save);
		while (save->index_b > 0
			&& save->rr-- != 0)
			ft_rrb(save);
		while (save->index_a > 0
			&& save->rrp-- != 0 && save->int_n_gr > 1)
		{
			ft_rra(save);
			ft_pb(save);
		}
	}
	while (save->index_a != 0)
	{
		ft_pb(save);
	}
	save->int_gr = save->int_gr / 3;
	save->int_n_gr *= 3;
	return ;
}

void	ft_start_rra(t_mem *save)
{
	while ((long long)save->l_lst_a->prev->content < save->int_m2
		&& save->int_n_gr == 1)
		ft_rra(save);
	return ;
}

void	ft_while_gr_a(t_mem *save)
{
	save->gr = 0;
	while (save->gr++ < save->int_gr && save->index_a > 0)
	{
		if (ft_m2(save) == 0)
			ft_pb(save);
		if (save->index_b > 2
			&& (long long)save->l_lst_b->content > save->int_m1
			&& save->int_n_gr > 1)
		{
			ft_rb(save);
			save->rr++;
		}
		else if (save->index_b > 2
			&& (long long)save->l_lst_b->content < save->int_m1
			&& save->int_n_gr == 1)
			ft_rb(save);
	}
	while (save->index_a > 0
		&& (long long)save->l_lst_a->content >= save->int_s
		&& (long long)save->l_lst_a->content <= save->int_m2)
		ft_pb(save);
	return ;
}

int	ft_m2(t_mem *save)
{
	if (save->index_a > 0
		&& (long long)save->l_lst_a->content > save->int_m2
		&& (long long)save->l_lst_a->content <= save->int_e)
	{
		ft_ra(save);
		save->rrp++;
		return (1);
	}
	return (0);
}

void	ft_sch_nb_a(t_mem *save)
{
	ft_sch_start(save->l_lst_a, save);
	ft_sch_end(save->l_lst_a, save);
	ft_sch_m2(save->l_lst_a, save->int_gr, save);
	ft_sch_m1(save->l_lst_a, save->int_gr, save);
	return ;
}
