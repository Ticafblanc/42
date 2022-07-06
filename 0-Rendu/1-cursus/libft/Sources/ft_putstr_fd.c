/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:34:37 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/13 05:44:03 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	count;

	if (s)
	{
		count = 0;
		while (s[count])
		{
			ft_putchar_fd(s[count], fd);
			count++;
		}
	}
	return ;
}
