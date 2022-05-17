/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_sort_lst_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/08 09:02:29 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sch_start(t_struct *l_lst, t_mem *save)
{
	int	i;

	i = 0;
	save->int_s = (long long)l_lst->content;
	while (i++ < save->int_gr)
	{
		if ((long long)l_lst->content < save->int_s)
			save->int_s = (long long)l_lst->content;
		l_lst = l_lst->next;
	}
}

void	ft_sch_end(t_struct *l_lst, t_mem *save)
{
	int	i;

	i = 0;
	save->int_e = save->int_s;
	while (i++ < save->int_gr)
	{
		if ((long long)l_lst->content > save->int_e)
			save->int_e = (long long)l_lst->content;
		l_lst = l_lst->next;
	}
}

void	ft_sch_m2(t_struct *l_lst, int index, t_mem *save)
{
	int			i;
	int			i2;
	int			i3;
	t_struct	*l_lst_m;

	i = 0;
	i3 = 0;
	i2 = save->int_e;
	l_lst_m = l_lst;
	while (i++ < (index / 3))
	{
		save->int_m2 = save->int_s;
		while (i3++ < index)
		{
			if ((long long)l_lst->content > save->int_m2
				&& (long long)l_lst->content < i2)
				save->int_m2 = (long long)l_lst->content;
			l_lst = l_lst->next;
		}
		i3 = 0;
		i2 = save->int_m2;
		l_lst = l_lst_m;
	}
}

void	ft_sch_m1(t_struct *l_lst, int index, t_mem *save)
{
	int			i;
	int			i2;
	int			i3;
	t_struct	*l_lst_m;

	i = 0;
	i2 = save->int_s;
	i3 = 0;
	l_lst_m = l_lst;
	while (i++ < (index / 3))
	{
		save->int_m1 = save->int_e;
		while (i3++ < index)
		{
			if ((long long)l_lst->content < save->int_m1
				&& (long long)l_lst->content > i2)
				save->int_m1 = (long long)l_lst->content;
			l_lst = l_lst->next;
		}
		i3 = 0;
		i2 = save->int_m1;
		l_lst = l_lst_m;
	}
	return ;
}
