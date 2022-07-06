/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 06:01:42 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/29 10:09:35 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	while (n-- > 0)
		((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	return (dest);
}
