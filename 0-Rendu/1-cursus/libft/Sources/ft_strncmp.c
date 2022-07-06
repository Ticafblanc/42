/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:03:08 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/09/30 15:03:11 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	c;

	c = 0;
	if (n == 0)
		return (0);
	while (c < n - 1 && s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c])
		c++;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
