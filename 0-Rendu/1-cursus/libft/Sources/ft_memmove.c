/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 06:01:42 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/27 13:33:51 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*t;
	int			i;

	i = 0;
	t = (const char *)src;
	if (dest == src)
		return (dest);
	if (src < dest)
		while (len-- > 0)
			((unsigned char *)dest)[len] = t[len];
	else
	{
		while (len-- > 0)
		{
			((unsigned char *)dest)[i] = t[i];
			i++;
		}
	}
	return (dest);
}
