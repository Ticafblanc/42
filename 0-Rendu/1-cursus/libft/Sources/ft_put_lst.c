/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:15:49 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/22 14:50:14 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_put_l_lst(t_struct *l_lst, int index)
{
	while (index-- != 0)
	{
		ft_putnbr_fd((long long)l_lst->content, 1);
		ft_putstr_fd(" \n", 1);
		l_lst = l_lst->next;
	}
}
