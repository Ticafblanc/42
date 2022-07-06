/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 06:03:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 11:28:30 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_struct	*ft_lst_new(void *content)
{
	t_struct	*l_lst;

	l_lst = (t_struct *)malloc(sizeof(t_struct));
	if (!l_lst)
		return (l_lst = NULL);
	l_lst->next = l_lst;
	l_lst->prev = l_lst;
	l_lst->content = content;
	return (l_lst);
}
