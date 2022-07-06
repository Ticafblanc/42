/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 05:45:50 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/13 05:46:15 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count(char const *str, char c)
{
	size_t	st;
	int		trigger;

	st = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			st++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (st);
}

char	**ft_split(char const *s, char c)

{
	size_t	st;
	size_t	st2;
	int		i;
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)ft_calloc((count(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	st = 0;
	st2 = 0;
	i = -1;
	while (st <= ft_strlen(s))
	{
		if (s[st] != c && i < 0)
			i = st;
		else if (i >= 0 && (s[st] == c || st == ft_strlen(s)))
		{
			str[st2++] = ft_substr(s, i, (st - i));
			i = -1;
		}
		st++;
	}
	return (str);
}
