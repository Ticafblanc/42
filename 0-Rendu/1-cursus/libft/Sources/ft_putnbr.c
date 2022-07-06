/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoqouocb@student.42quebec.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:30 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 14:07:15 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putnbr(long n)
{
	char	c;
	int		printed;

	printed = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		printed++;
		n = -n;
	}
	if (n / 10 > 0)
		printed += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	printed++;
	return (printed);
}
