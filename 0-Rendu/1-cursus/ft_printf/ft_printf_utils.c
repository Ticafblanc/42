/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:02:23 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/01/28 11:04:10 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char c, int t)
{
	char	*set;
	int		output;

	output = 0;
	if (c == 'X')
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (c == 'p')
	{
		if (t == 1)
			output += ft_putstr("0x");
		if (n / 16 > 0)
			output += ft_puthex(n / 16, c, 0);
	}
	else
	{
		if ((unsigned int)n / 16 > 0)
			output += ft_puthex((unsigned int)n / 16, c, 0);
	}
	ft_putchar(set[n % 16]);
	output++;
	return (output);
}

int	ft_putnbr(long l)
{
	int	output;

	output = 0;
	if (l < 0)
	{
		output += ft_putchar(45);
		l *= -1;
	}
	if (l > 9)
		output += ft_putnbr(l / 10);
	ft_putchar(l % 10 + 48);
	output++;
	return (output);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i += ft_putchar(s[i]);
	else
		i += ft_putstr("(null)");
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
