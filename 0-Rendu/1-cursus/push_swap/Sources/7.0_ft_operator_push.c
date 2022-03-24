/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.0_ft_operator_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:14:14 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/04 15:57:34 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_mem *save)
{
	ft_push(&save->l_lst_b, &save->l_lst_a, &save->index_b, &save->index_a);
	ft_putstr_fd("pa\n", 1);
	return ;
}

void	ft_pb(t_mem *save)
{
	ft_push(&save->l_lst_a, &save->l_lst_b, &save->index_a, &save->index_b);
	ft_putstr_fd("pb\n", 1);
	return ;
}

void	ft_push(t_struct **l_lst_s, t_struct **l_lst_a, int *i_s, int *i_a)
{
	t_struct	*l_lst_t;

	l_lst_t = (*l_lst_a);
	(*l_lst_a) = (*l_lst_s);
	(*l_lst_s) = (*l_lst_a)->next;
	(*l_lst_s)->prev = (*l_lst_a)->prev;
	(*l_lst_s)->prev->next = (*l_lst_s);
	if (*i_a == 0)
	{
		(*l_lst_a)->prev = (*l_lst_a);
		(*l_lst_a)->next = (*l_lst_a);
	}
	else
	{
		(*l_lst_a)->prev = l_lst_t->prev;
		(*l_lst_a)->next = l_lst_t;
		(*l_lst_a)->next->prev = (*l_lst_a);
		(*l_lst_a)->prev->next = (*l_lst_a);
	}
	(*i_s)--;
	(*i_a)++;
	if (*i_s == 0)
		(*l_lst_s) = NULL;
	return ;
}
