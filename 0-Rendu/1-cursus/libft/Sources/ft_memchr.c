/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:47:00 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/30 15:47:03 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (((const char *)s)[count] == (char)c)
			return ((void *)(s + count));
		count++;
	}
	return (0);
}
