/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:04:34 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/13 10:05:45 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
