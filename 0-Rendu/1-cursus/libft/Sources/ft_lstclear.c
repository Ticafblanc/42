/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 05:28:56 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/14 05:52:02 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*slst;

	if (!*lst)
		return ;
	while (*lst && del)
	{
		slst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = slst;
	}
	*lst = NULL;
}
