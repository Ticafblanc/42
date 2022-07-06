/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:20:06 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/07 14:15:32 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	neg(int c)
{
	if (c == 45)
		return (-1);
	else if (c == 43)
		return (1);
	else if (c == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t		c;
	long long	l;
	int			n;
	int			n2;

	c = 0;
	n = 1;
	l = 0;
	n2 = 0;
	while (str[c] && ((str[c] >= 9 && str[c] <= 13) || str[c] == 32))
		c++;
	if (str[c] == 45 || str[c] == 43)
	{
		n = neg(str[c]);
		c++;
	}
	while (str[c] && (str[c] >= 48 && str[c] <= 57))
	{
		l = l * 10 + str[c] - 48;
		c++;
		n2++;
	}
	if (n2 > 20)
		return (neg(n));
	return (l * n);
}
