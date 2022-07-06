/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:34:05 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/24 08:34:08 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long int	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd(45, fd);
		l *= -1;
	}
	if (l > 9)
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd(l % 10 + 48, fd);
	}
	else
		ft_putchar_fd(l + 48, fd);
}
