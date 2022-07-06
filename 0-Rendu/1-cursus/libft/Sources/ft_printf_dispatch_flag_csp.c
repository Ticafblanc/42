/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branch_csp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquoc@student.42quebec.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:55:57 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 13:43:22 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_print_char(char c, struct s_flgs flags)
{
	if (flags.width > 0 && flags.minus == 1)
		return (ft_putchar_wid_min(c, flags.width));
	else if (flags.width > 0 && flags.zero == 1)
		return (ft_putchar_wid_zero(c, flags.width));
	else if (flags.width > 0)
		return (ft_putchar_wid(c, flags.width));
	else
		return (ft_putchar(c));
}

int	ft_print_str(char *s, struct s_flgs flags)
{
	static char	n[8] = "(null)";
	int			pre_size;
	int			width_size;

	pre_size = flags.precision;
	width_size = 0;
	if (s == NULL)
		s = n;
	if (ft_str_len(s) < flags.precision)
		pre_size = ft_strlen(s);
	if (flags.width > pre_size)
		width_size = (flags.width - pre_size);
	if (flags.width > 0 && flags.dot == 1)
		return (ft_putstr_wid_pre(s, flags, pre_size, width_size));
	else if (flags.width > 0)
		return (ft_putstr_wid(s, flags));
	else if (flags.dot == 1)
		return (ft_putstr_pre(s, pre_size));
	else
		return (ft_putstr(s));
}

int	ft_print_mem(unsigned long n, struct s_flgs flags)
{
	int	i;

	i = 0;
	if (flags.dot == 1 && flags.precision == 0 && n == 0)
	{
		while (flags.minus == 0 && i++ < flags.width - 2)
			write(1, " ", 1);
		write(1, "0x", 2);
		while (flags.minus == 1 && i++ < flags.width - 2)
			write(1, " ", 1);
		return (i + 1);
	}
	if (flags.width > 0 && flags.dot == 1)
		return (ft_putmem_prewid(n, flags));
	if (flags.width > 0 && flags.zero == 0)
		return (ft_putmem_wid(n, flags));
	else if (flags.dot == 1 || (flags.width > 0 && flags.zero == 1))
		return (ft_putmem_pre(n, flags));
	else
		return (ft_putmem(n, 1));
}
