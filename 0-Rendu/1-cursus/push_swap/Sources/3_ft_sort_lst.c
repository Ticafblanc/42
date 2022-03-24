/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_sort_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/08 11:53:30 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_lst(t_mem *save)
{
	if (save->index_a == 2)
	{
		ft_sa(save);
		return ;
	}
	save->int_gr = save->index_a;
	save->int_n_gr = 1;
	if (save->index_a > 5)
	{
		ft_sort_gr(save);
		while (save->int_gr > 30)
		{
			ft_sort_grr(save);
			ft_sort_gr(save);
		}
	}
	while (save->index_a > 3)
		ft_pb(save);
	while (save->index_a < 3)
		ft_pa(save);
	ft_sort_3(save);
	ft_spot(save);
	return ;
}

int	ft_check_lst(t_struct *l_lst, int index)
{
	int	i;

	i = 0;
	while (i++ < index - 1)
	{
		if ((long long)l_lst->content
			> (long long)l_lst->next->content)
			return (0);
		l_lst = l_lst->next;
	}
	return (1);
}

void	ft_sort_3(t_mem *save)
{
	if ((long long)save->l_lst_a->content
		> (long long)save->l_lst_a->next->content
		&& (long long)save->l_lst_a->content
		> (long long)save->l_lst_a->prev->content
		&& ft_check_lst(save->l_lst_a, save->index_a) == 0)
		ft_ra(save);
	else if ((long long)save->l_lst_a->next->content
		> (long long)save->l_lst_a->content
		&& (long long)save->l_lst_a->next->content
		> (long long)save->l_lst_a->prev->content
		&& ft_check_lst(save->l_lst_a, save->index_a) == 0)
		ft_rra(save);
	if ((long long)save->l_lst_a->content
		> (long long)save->l_lst_a->next->content
		&& ft_check_lst(save->l_lst_a, save->index_a) == 0)
		ft_sa(save);
	return ;
}

void	ft_spot(t_mem *save)
{
	while (save->index_b > 0)
	{
		save->int_gr = save->index_a;
		ft_sch_start(save->l_lst_a, save);
		ft_sch_end(save->l_lst_a, save);
		if ((long long)save->l_lst_b->content < save->int_s)
		{
			ft_return_zero(save);
			ft_pa(save);
		}
		else if ((long long)save->l_lst_b->content > save->int_e)
		{
			ft_return_zero(save);
			ft_pa(save);
			save->pos--;
		}
		else
		{
			ft_pos(save);
		}
	}
	ft_return_zero(save);
	return ;
}

void	ft_finish(t_mem *save)
{
	save->pos = 0;
	ft_sch_start(save->l_lst_a, save);
	while ((long long)save->l_lst_a->content
		!= save->int_s)
	{
		save->l_lst_a = save->l_lst_a->prev;
		save->pos++;
	}
	if (save->pos >= save->index_a / 2)
		save->pos *= -1;
	ft_return_zero(save);
}
