/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@42quebec.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:44:59 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/08/24 08:45:15 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*srcr;
	int		a;

	a = 0;
	srcr = malloc(sizeof(*src));
	if (srcr == NULL)
		return (NULL);
	while (src[a] != '\0')
	{
		srcr[a] = src[a];
		a++;
	}
	srcr[a] = '\0';
	return (srcr);
}
