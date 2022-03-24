/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:43:28 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/22 16:14:53 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getchar(char *str, int fd)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = BUFFER_SIZE + 1;
	while (str[i] != '\n' && str[i] != '\0')
	{
		str[++i] = ft_fgets(fd);
		if ((i2 - i) == 0)
		{
			str = ft_realloc(str, (i + i2 + 2));
			i2 += i;
		}
	}
	str[++i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (0);
	str[0] = ft_fgets(fd);
	if (str[0] == '\0')
	{
		free (str);
		return (0);
	}
	str = ft_getchar(str, fd);
	return (str);
}
