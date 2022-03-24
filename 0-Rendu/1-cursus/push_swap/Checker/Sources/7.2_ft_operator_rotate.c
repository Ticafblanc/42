/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.2_ft_operator_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:14:14 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/21 10:34:41 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_ra(t_mem *save)
{
	ft_rotate(&save->l_lst_a);
	return ;
}

void	ft_rb(t_mem *save)
{
	ft_rotate(&save->l_lst_b);
	return ;
}

void	ft_rr(t_mem *save)
{
	ft_rotate(&save->l_lst_a);
	ft_rotate(&save->l_lst_b);
	ft_putstr_fd("rr\n", 1);
	return ;
}
