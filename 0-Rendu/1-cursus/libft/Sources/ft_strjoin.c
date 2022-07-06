/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 07:49:19 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/04 07:49:26 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	st;

	if (!s1 || !s2)
		return (NULL);
	st = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(st * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, st);
	ft_strlcat(str, s2, st);
	return (str);
}
