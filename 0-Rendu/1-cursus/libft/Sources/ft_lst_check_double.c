/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_check_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 06:03:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 11:38:03 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lst_check_double(void *content, t_struct *l_lst, int index)
{
	int	i;

	i = 0;
	while (i++ < index - 1)
	{
		l_lst = l_lst->next;
		if (content == l_lst->content)
			return (0);
	}
	return (1);
}
