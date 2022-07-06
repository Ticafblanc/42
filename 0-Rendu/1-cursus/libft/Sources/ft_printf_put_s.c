/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:22:01 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/05 14:04:08 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putstr_wid_pre(char *s, struct s_flgs flags, int pre_si, int wid_si)
{
	int		i;
	char	c;

	c = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		c = '0';
	i = 0;
	while (flags.minus == 1 && i < flags.precision && s[i] != '\0')
		write(1, &s[i++], 1);
	i = 0;
	while (i++ < wid_si)
		write(1, &c, 1);
	i = 0;
	while (flags.minus == 0 && i < flags.precision && s[i] != '\0')
		write(1, &s[i++], 1);
	if (pre_si > flags.width)
		return (pre_si);
	return (flags.width);
}

int	ft_putstr_wid(char *s, struct s_flgs flags)
{
	int		padsize;
	int		i;
	char	c;

	padsize = 0;
	c = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		c = '0';
	if (flags.width > ft_str_len(s))
			padsize = (flags.width - ft_str_len(s));
	i = 0;
	while (flags.minus == 1 && s[i] != '\0')
		write(1, &s[i++], 1);
	i = 0;
	while (i++ < padsize)
		write(1, &c, 1);
	i = 0;
	while (flags.minus == 0 && s[i] != '\0')
		write(1, &s[i++], 1);
	if (ft_str_len(s) > flags.width)
		return (ft_str_len(s));
	return (flags.width);
}

int	ft_putstr_pre(char *s, int pre_size)
{
	int	i;

	i = 0;
	while (i < pre_size && s[i] != '\0')
		write(1, &s[i++], 1);
	return (pre_size);
}
