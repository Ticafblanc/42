/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branch_duxo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:57:40 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 14:07:12 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_print_nbr(long n, struct s_flgs flags)
{
	int	i2;

	i2 = 0;
	if (n >= 0 && (flags.plus == 1))
		ft_printf_flag_app(2, &i2);
	if (n >= 0 && (flags.space == 1 && flags.plus == 0))
		ft_printf_flag_app(3, &i2);
	if (flags.dot == 1 && flags.precision == 0 && n == 0)
	{
		ft_printf_flag_app(1, &flags.width);
		return (flags.width);
	}
	else if (flags.width > 0 && flags.dot == 1)
		return (ft_putnbr_prewid(n, flags) + i2);
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_putnbr_wid(n, flags) + i2);
	else if (flags.width > 0 && flags.zero == 1 && flags.minus == 1)
		return (ft_putnbr_wid(n, flags) + i2);
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putnbr_pre(n, flags) + i2);
	else
		return (ft_putnbr(n) + i2);
}

int	ft_print_hex(unsigned int n, struct s_flgs flags, char c)
{
	int	i2;
	int	cas;

	i2 = 0;
	cas = 0;
	if (c == 'X')
		cas = 1;
	if (n != 0 && flags.htag == 1)
		i2 = ft_print_htag(cas);
	if (flags.dot == 1 && flags.precision == 0 && n == 0)
	{
		ft_printf_flag_app(1, &flags.width);
		return (flags.width);
	}	
	else if (flags.width > 0 && flags.dot == 1)
		return (ft_puthex_prewid(n, flags, cas) + i2);
	else if (flags.width > 0 && flags.zero == 0)
		return (ft_puthex_wid(n, flags, cas) + i2);
	else if (flags.width > 0 && flags.zero == 1 && flags.minus == 1)
		return (ft_puthex_wid(n, flags, cas) + i2);
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_puthex_pre(n, flags, cas) + i2);
	else
		return (ft_puthex(n, cas) + i2);
}

int	ft_print_htag(int cas)
{
	if (cas == 0)
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	return (2);
}

int	ft_print_other(char c, struct s_flgs flags)
{
	int	padding;

	padding = flags.width - 1;
	if (c == '\0')
		return (0);
	while (flags.minus == 0 && flags.zero == 0 && padding-- > 0)
		write(1, " ", 1);
	while (flags.minus == 0 && flags.zero == 1 && padding-- > 0)
		write(1, "0", 1);
	write(1, &c, 1);
	while (flags.minus == 1 && padding-- > 0)
		write(1, " ", 1);
	if (flags.width > 0)
		return (flags.width);
	else
		return (1);
}
