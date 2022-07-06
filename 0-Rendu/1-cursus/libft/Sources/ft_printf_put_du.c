/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_du.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoqouocb@student.42quebec.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:13:30 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 14:07:15 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putnbr_prewid(long n, struct s_flgs flags)
{
	int		printed;
	int		count;
	int		padding;

	printed = 0;
	count = flags.precision - ft_nbrlen(n);
	ft_printf_flag_app_2(1, &count, n);
	ft_printf_flag_app_2(2, &count, n);
	padding = flags.width - ft_nbrlen(n) - count;
	ft_printf_flag_app_2(2, &padding, n);
	printed += padding + count + ft_nbrlen(n);
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (count-- > 0)
		write(1, "0", 1);
	ft_putnbr(n);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int	ft_putnbr_wid(long n, struct s_flgs flags)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags.width - ft_nbrlen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	printed += ft_putnbr(n);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}

int	ft_putnbr_pre(long n, struct s_flgs flags)
{
	int		printed;
	int		count;

	printed = 0;
	count = flags.width - ft_nbrlen(n);
	if (flags.dot == 1)
		count = flags.precision - ft_nbrlen(n);
	if (n < 0 && flags.dot == 1)
		count -= -1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		printed++;
	}
	while (count-- > 0)
	{
		write(1, "0", 1);
		printed++;
	}
	printed += ft_putnbr(n);
	return (printed);
}
