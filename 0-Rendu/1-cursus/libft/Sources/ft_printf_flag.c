/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:05:59 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 16:11:57 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_is_conversion_specifiers(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_valid_flag(const char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_star(const char *s, int *i, va_list args)
{
	int	num;

	num = 0;
	if (s[*i] == '.')
		(*i)++;
	if (s[*i] == '*')
	{
		num = va_arg(args, unsigned int);
		return (num);
	}
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		num = num * 10 + (s[*i] - 48);
		(*i)++;
	}
	(*i)--;
	return (num);
}

void	ft_neg_star(struct s_flgs *flags)
{
	if (flags->precision < 0)
	{
		flags->dot = 0;
		flags->precision = 0;
	}
	else if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	return ;
}
