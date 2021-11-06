/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:48:01 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/14 10:05:14 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i != n)
	{
		if (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i <= n - 1)
		{
			i++;
		}
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
