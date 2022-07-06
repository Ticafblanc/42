/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:09:43 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/30 08:09:48 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_getchar(const char *str, int c)
{
	unsigned int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == c)
		{
			count++;
			return (count);
		}
		count++;
	}
	return (0);
}

char	*ft_save(char **s_buff)
{
	char	*str;
	int		len;
	int		s_len;
	char	*t_buff;

	len = ft_getchar(*s_buff, '\n');
	s_len = ft_strlen(*s_buff);
	if (s_len == len)
		return (ft_return(&*s_buff));
	else
	{
		str = ft_substr(*s_buff, 0, len);
		t_buff = *s_buff;
		*s_buff = ft_substr(t_buff, len, (s_len - len));
		free (t_buff);
	}
	return (str);
}

char	*ft_return(char **s_buff)
{
	char	*str;

	if (*s_buff)
	{
		str = *s_buff;
		*s_buff = NULL;
		free (*s_buff);
		return (str);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*s_buff[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*t_buff;
	int			len_buff;

	len_buff = 1;
	while (len_buff > 0)
	{
		len_buff = read(fd, buff, BUFFER_SIZE);
		if (len_buff <= 0 && !s_buff[fd])
			return (NULL);
		buff[len_buff] = '\0';
		if (!s_buff[fd])
			s_buff[fd] = ft_substr(buff, 0, ft_strlen(buff));
		else
		{
			t_buff = ft_strjoin(s_buff[fd], buff);
			free(s_buff[fd]);
			s_buff[fd] = t_buff;
		}
		if (ft_getchar(s_buff[fd], '\n'))
			return (ft_save(&s_buff[fd]));
	}
	return (ft_return(&s_buff[fd]));
}
