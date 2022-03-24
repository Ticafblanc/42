/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft_spot_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:09:45 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/07 11:18:54 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pos(t_mem *save)
{
	while ((long long)save->l_lst_b->content
		> (long long)save->l_lst_a->content)
	{
		ft_ra(save);
		save->pos++;
	}
	while ((long long)save->l_lst_b->content
		< (long long)save->l_lst_a->prev->content)
	{
		ft_rra(save);
		save->pos--;
	}
	ft_pa(save);
	if (save->pos < 0)
		save->pos--;
}

void	ft_return_zero(t_mem *save)
{
	while (save->pos > 0)
	{
		save->pos--;
		ft_rra(save);
	}
	while (save->pos < 0)
	{
		save->pos++;
		ft_ra(save);
	}
	return ;
}
