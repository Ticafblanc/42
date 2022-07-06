/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 05:10:20 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/06 10:25:43 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	return (str);
}	
