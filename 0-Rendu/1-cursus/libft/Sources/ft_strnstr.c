/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 07:35:11 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/07 13:47:10 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	st;

	if (*needle == '\0')
		return ((char *)haystack);
	st = ft_strlen(needle);
	while (*haystack != '\0' && len >= st)
	{
		len--;
		if (ft_strncmp(haystack, needle, st) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
