/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:23:47 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/01 09:50:34 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_puthex_prewid(unsigned int n, struct s_flgs flags, int cap)
{
	int		printed;
	int		count;
	int		padding;

	printed = 0;
	count = flags.precision - ft_hexlen(n);
	ft_printf_flag_app_2(2, &count, n);
	padding = flags.width - ft_hexlen(n) - count;
	ft_printf_flag_app_2(2, &padding, n);
	printed += padding + count + ft_hexlen(n);
	while (flags.minus == 0 && padding-- > 0)
		write(1, " ", 1);
	while (count-- > 0)
		write(1, "0", 1);
	ft_puthex(n, cap);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	return (printed);
}

int	ft_puthex_pre(unsigned int n, struct s_flgs flags, int cap)
{
	int		printed;
	int		count;

	printed = 0;
	count = flags.width;
	if (flags.dot == 1)
		count = flags.precision;
	count -= ft_hexlen(n);
	while (count-- > 0)
	{
		write(1, "0", 1);
		printed++;
	}
	printed += ft_puthex(n, cap);
	return (printed);
}

int	ft_puthex_wid(unsigned int n, struct s_flgs flags, int cap)
{
	int		printed;
	int		padding;

	printed = 0;
	padding = flags.width - ft_hexlen(n);
	while (flags.minus == 0 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	printed += ft_puthex(n, cap);
	while (flags.minus == 1 && padding-- > 0)
	{
		write(1, " ", 1);
		printed++;
	}
	return (printed);
}
