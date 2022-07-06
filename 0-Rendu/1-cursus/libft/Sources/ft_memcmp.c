/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 04:46:54 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/01 07:54:03 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		if (((const unsigned char *)s1)[c] != ((const unsigned char *)s2)[c])
			return (((const unsigned char *)s1)[c]
					- ((const unsigned char *)s2)[c]);
		c++;
	}
	return (0);
}
