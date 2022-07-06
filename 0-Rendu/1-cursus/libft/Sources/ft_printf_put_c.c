/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:11:58 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/01 09:13:10 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putchar_wid_min(char c, int width)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	while (count++ < width - 1)
		write(1, " ", 1);
	return (width);
}

int	ft_putchar_wid_zero(char c, int width)
{
	int	count;

	count = 0;
	while (count++ < width - 1)
		write(1, "0", 1);
	write(1, &c, 1);
	return (width);
}

int	ft_putchar_wid(char c, int width)
{
	int	count;

	count = 0;
	while (count++ < width - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}
