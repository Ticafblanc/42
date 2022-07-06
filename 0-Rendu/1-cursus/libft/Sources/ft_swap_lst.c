/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:14:14 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/03 09:16:55 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(t_struct *l_lst, t_struct *l_lst_n)
{
	void	*t;

	t = l_lst->content;
	l_lst->content = l_lst_n->content;
	l_lst_n->content = t;
	return ;
}
