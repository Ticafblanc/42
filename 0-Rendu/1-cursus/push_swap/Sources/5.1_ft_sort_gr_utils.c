/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.1_ft_sort_gr_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/08 12:18:22 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_grr(t_mem *save)
{
	save->n_gr = 0;
	while (save->n_gr++ != save->int_n_gr && save->index_b > 0)
	{
		save->rr = 0;
		save->rrp = 0;
		ft_sch_nb_b(save);
		ft_while_gr_b(save);
		while (save->index_a > 0
			&& save->rr-- != 0)
			ft_rra(save);
		while (save->index_b > 0
			&& save->rrp-- != 0 && save->int_n_gr > 1)
		{
			ft_rrb(save);
			ft_pa(save);
		}
	}
	while (save->index_b != 0)
		ft_pa(save);
	save->int_gr = save->int_gr / 3;
	save->int_n_gr *= 3;
	return ;
}

void	ft_while_gr_b(t_mem *save)
{
	save->gr = 0;
	while (save->gr++ < save->int_gr && save->index_b > 0)
	{
		if (ft_m1(save) == 0)
			ft_pa(save);
		if (save->int_n_gr == 3
			&& save->n_gr == 1)
		{
			if (save->index_a > 2
				&& (long long)save->l_lst_a->content > save->int_m2)
				ft_ra(save);
		}
		else if (save->index_a > 2
			&& (long long)save->l_lst_a->content < save->int_m2)
		{
			ft_ra(save);
			save->rr++;
		}
	}
	while (save->index_b > 0
		&& (long long)save->l_lst_b->content > save->int_m1
		&& (long long)save->l_lst_b->content <= save->int_e)
		ft_pa(save);
	return ;
}

int	ft_m1(t_mem *save)
{
	if (save->index_b > 0
		&& (long long)save->l_lst_b->content < save->int_m1
		&& (long long)save->l_lst_b->content >= save->int_s)
	{
		ft_rb(save);
		save->rrp++;
		return (1);
	}
	return (0);
}

void	ft_sch_nb_b(t_mem *save)
{
	ft_sch_start(save->l_lst_b, save);
	ft_sch_end(save->l_lst_b, save);
	ft_sch_m2(save->l_lst_b, save->int_gr, save);
	ft_sch_m1(save->l_lst_b, save->int_gr, save);
	return ;
}
