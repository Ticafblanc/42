/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:02:26 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/06 15:21:12 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	count;

	count = 0;
	count = ft_strlen(s);
	while (s[count] != (unsigned char)c)
	{
		if (count == 0)
			return (NULL);
		count--;
	}
	return ((char *)(s + count));
}
