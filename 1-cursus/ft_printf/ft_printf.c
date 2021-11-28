/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 04:40:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/11/10 11:51:25 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthex(unsigned long n, char c, int t)
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
		if (n / 16  > 0)
			output += ft_puthex(n / 16, c, 0);
	}
	else
	{
		
		if ((unsigned int)n / 16  > 0)
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

int		ft_putstr(char *s)
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

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_dispatch(const char *str, int *i, va_list input)
{
	if (str[*i] == 'c')
		return (ft_putchar(va_arg(input, int)));
	else if (str[*i] == 's')
		return (ft_putstr(va_arg(input, char *)));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr(va_arg(input, int)));
	else if (str[*i] == 'u')
		return (ft_putnbr(va_arg(input, unsigned int)));
	else if (str[*i] == 'x' || str[*i] == 'X' || str [*i] == 'p')
		return (ft_puthex(va_arg(input, unsigned long), str[*i], 1));
	else if (str[*i] == '%')
		return (ft_putchar('%'));	
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list	input;
	int		output;
	int		i;

	va_start(input, str);
	i = 0;
	output = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			output += ft_dispatch(str, &i, input);
			i++;
		}
		else
			output += ft_putchar(str[i++]);
	}
	va_end(input);
	return (output);
}
