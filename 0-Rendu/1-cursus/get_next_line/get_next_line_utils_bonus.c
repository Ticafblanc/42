/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:09:13 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/30 08:16:53 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	st;

	if (!s1 || !s2)
		return (NULL);
	st = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(st);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, st);
	ft_strlcat(str, s2, st);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(ft_strlen(s) + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, s, (ft_strlen(s) + 1));
		return (str);
	}
	if (ft_strlen (s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy (str, s + start, len + 1);
	return (str);
}

size_t	ft_strlen(const char *maxlen)
{
	unsigned int	count;

	count = 0;
	while (maxlen[count])
	{
		count++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

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
