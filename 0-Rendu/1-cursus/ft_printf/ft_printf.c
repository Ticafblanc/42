/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 04:40:39 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/01/28 11:07:10 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(const char *str, int *i, va_list input)
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

int	ft_printf(const char *str, ...)
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
