/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 06:03:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/13 06:03:52 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_add(t_struct *l_lst, t_struct *l_lst_t)
{
	l_lst_t->prev = l_lst->prev;
	l_lst_t->next = l_lst;
	l_lst->prev = l_lst_t;
	l_lst_t->prev->next = l_lst_t;
	return ;
}
