/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.1_ft_operator_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:14:14 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/03 09:16:55 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_sa(t_mem *save)
{
	ft_swap(save->l_lst_a, save->l_lst_a->next);
	return ;
}

void	ft_sb(t_mem *save)
{
	ft_swap(save->l_lst_b, save->l_lst_b->next);
	return ;
}

void	ft_ss(t_mem *save)
{
	ft_swap(save->l_lst_a, save->l_lst_a->next);
	ft_swap(save->l_lst_b, save->l_lst_b->next);
	ft_putstr_fd("ss\n", 1);
	return ;
}
