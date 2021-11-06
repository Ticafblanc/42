/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:48:01 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/12 16:17:05 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	int		a;
	int		b;

	if (to_find[0] == '\0')
		return (str);
	a = 0;
	while (str[a] != '\0')
	{
		b = 0;
		if (str[a] == to_find[b])
		{
			while (str[a + b] == to_find[b])
			{
				b++;
				if (to_find[b] == '\0')
					return (&str[a]);
			}
		}
		a++;
	}
	return (0);
}
