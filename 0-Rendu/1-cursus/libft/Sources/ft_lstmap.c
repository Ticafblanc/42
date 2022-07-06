/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 06:24:24 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/14 11:20:27 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*t_lst;

	if (!lst || !f)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		t_lst = ft_lstnew (f(lst->content));
		if (!t_lst)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&n_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&n_lst, t_lst);
	}
	return (n_lst);
}
