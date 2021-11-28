/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_untils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:49:21 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/29 14:44:40 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_fgets(int fd)
{
	static char	buff[BUFFER_SIZE];
	static char	*str_buff;
	static int	i = 0;
	char		c;

	if (i == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0)
			return (0);
		str_buff = buff;
	}
	c = *str_buff;
	str_buff++;
	i--;
	return (c);
}

char	*ft_realloc(char *ptr, size_t new_size)
{
	char	*t_ptr;
	size_t	i;

	t_ptr = ptr;
	ptr = (char *)malloc(new_size);
	i = -1;
	while (t_ptr[++i])
		ptr[i] = t_ptr[i];
	free(t_ptr);
	return (ptr);
}
