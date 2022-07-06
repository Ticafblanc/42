/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:39:10 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/29 12:57:21 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			srclen;
	size_t			dstlen;
	unsigned int	dstcount;
	unsigned int	srccount;

	srccount = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstcount = dstlen;
	if (dstsize == 0)
		return (srclen);
	if (dstsize < dstlen)
		return (srclen + dstsize);
	else
	{
		while (src[srccount] && (srccount + dstlen) < dstsize)
			dst[dstcount++] = src[srccount++];
		if ((srccount + dstlen) == dstsize && dstlen < dstsize)
			dst[--dstcount] = '\0';
		else
			dst[dstcount] = '\0';
		return (dstlen + srclen);
	}
}
