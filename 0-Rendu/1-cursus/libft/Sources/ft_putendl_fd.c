/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:33:32 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/13 05:42:33 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (s)
	{
		while (s[count])
		{
			ft_putchar_fd (s[count], fd);
			count++;
		}
		ft_putchar_fd('\n', fd);
	}
	return ;
}
