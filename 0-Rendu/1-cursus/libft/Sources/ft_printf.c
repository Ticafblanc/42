/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocn@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:49:02 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 16:10:15 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	flag(const char *str, int *i, struct s_flgs *flags, va_list args)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->htag = 0;
	flags->plus = 0;
	flags->space = 0;
	while (ft_is_conversion_specifiers(str[*i]) == 0 && is_valid_flag(str[*i]))
	{
		if (str[*i] == '-')
			flags->minus = 1;
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '#')
			flags->htag = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == ' ' && flags->plus == 0)
			flags->space = 1;
		else
			flag2(str, i, flags, args);
		(*i)++;
	}
}

void	flag2(const char *str, int *i, struct s_flgs *flags, va_list args)
{
	if (str[*i] == '.')
	{
		flags->dot = 1;
		flags->precision = ft_atoi_star(str, i, args);
	}
	else if (str[*i] == '*' || (str[*i] >= '1' && str[*i] <= '9'))
		flags->width = ft_atoi_star(str, i, args);
	if (flags->precision < 0 || flags->width < 0)
		ft_neg_star(flags);
}

int	ft_dispatch(const char *str, int *i, va_list args)
{
	struct s_flgs	flags;
	int				printed;

	(*i)++;
	flag(str, i, &flags, args);
	if (str[*i] == 'c')
		printed = ft_print_char(va_arg(args, int), flags);
	else if (str[*i] == 's')
		printed = ft_print_str(va_arg(args, char *), flags);
	else if (str[*i] == 'p')
		printed = ft_print_mem(va_arg(args, unsigned long), flags);
	else if (str[*i] == 'd' || str[*i] == 'i')
		printed = ft_print_nbr(va_arg(args, int), flags);
	else if (str[*i] == 'u')
		printed = ft_print_nbr(va_arg(args, unsigned int), flags);
	else if (str[*i] == 'x' || str[*i] == 'X')
		printed = ft_print_hex(va_arg(args, unsigned int), flags, str[*i]);
	else
		printed = ft_print_other(str[*i], flags);
	if (str[*i] != '\0')
		(*i)++;
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, str);
	i = 0;
	printed = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			printed += ft_dispatch(str, &i, args);
		else
		{
			write(1, &str[i++], 1);
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
