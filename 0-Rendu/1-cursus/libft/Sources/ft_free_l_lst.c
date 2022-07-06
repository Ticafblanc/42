/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_l_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 05:28:56 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 11:32:38 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_l_lst(t_struct *l_lst, int index)
{
	int			i;
	t_struct	*l_lst_t;

	i = 0;
	while (i++ < index)
	{
		l_lst_t = l_lst->next;
		free(l_lst);
		l_lst = l_lst_t;
	}
	return ;
}
