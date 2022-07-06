/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:52:19 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/07 17:52:22 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	count(long long l)
{
	int		i;

	i = 0;
	if (l < 0)
	{
		l = l * -1;
		i++;
	}
	if (l == 0)
		i++;
	while (l > 0)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

char	*mal(int i)
{
	char	*str;

	str = ft_calloc(i + 1, sizeof(char));
	return (str);
}

char	*ft_itoa(int n)
{
	long long	l;
	char		*str;
	int			i;

	l = n;
	i = count(l);
	str = mal(i);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (l == 0)
	{
		*str = 48;
	}
	if (l < 0)
	{
		l = l * -1;
		*str = 45;
	}
	while (l > 0)
	{
		str[i--] = l % 10 + 48;
		l = l / 10;
	}
	return (str);
}
